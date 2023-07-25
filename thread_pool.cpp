/**
 * Thread pool that uses round robin scheduling to run tasks
 * Tasks are defined as functions given as void pointers, with args
 * Should print when certain tasks are completed
 * Bonus: show state of queue/threads
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <thread>
#include <vector>
#include <memory>
#include <deque>
#include <semaphore>
#include <unordered_map>
#include <iostream>
#include "thread_pool.h"

#define MAIN_THREAD_TIMEOUT (5)
#define N_JOBS (10)

struct work_data
{
    uint32_t time;
    uint32_t work_id;

    ~work_data(){
        std::cout << "work data is freed\n";
    }
};

struct thread_job
{

    void (*apply)(void *);
    void *args;

    thread_job(void (*fn)(void *), void *data)
    {
        this->apply = fn;
        this->args = data;
    }

    ~thread_job()
    {
        std::cout << "job data is freed\n";
        // Need to free underlying memory as cpp would only free the stack pointers.
        // Or just leave it to RAII
    }
};

void thread_task(thread_pool *pool)
{
    // have wait lock
    // thread_pool unlocks semaphore and makes thread do task, but without joining it.
    // thread should acuire thread_job unit from work queue (or wait if it is empty
    while (true)
    {
        std::cout << "Thread is waiting for task\n";
        sem_wait(&(pool->sema)); // wait for thread activation from execute.

        if (!pool->alive) break; // ensure destructor's post does not cause thread to start task

        // no task -> don't sem_post (avoid live lock) 
        //      i.e. wait for execute() to add task
        // has task -> free up queue and perform task.
        pool->queue_lock.lock();
        if (pool->queue.size() == 0) continue;
        thread_job *job = pool->queue[0];
        pool->queue.pop_front();
        pool->queue_lock.unlock();

        job->apply(job->args);

        // Debugging - shows how many tasks are left
        pool->queue_lock.lock();
        std::cout << "Tasks left " << pool->queue.size() << "\n";
        pool->queue_lock.unlock();
    }

    std::cout << "thread is joining\n";
}

thread_pool::thread_pool(size_t n)
{
    // Create 0 valued sempahore with size n at start i.e. all threads will wait
    sem_init(&sema, false, n);
    for (size_t i = 0; i < n; i++){
        sem_wait(&sema);
    }

    // Launch n threads
    this->size = n;
    for (size_t i = 0; i < n; i++)
    {
        std::thread *thread_ptr = new std::thread(thread_task, this);
        thread_available[thread_ptr] = true;
    }
}

thread_pool::~thread_pool()
{
    std::cout << "Thread pool destructor called\n";
    this->alive = false;

    // Release all semaphores so that they can return to start of while loop and join
    for (int i = 0; i < size; i++){
        sem_post(&sema);
    }

    // Join/terminate all threads
    for (auto &[thread_ptr, status] : thread_available)
    {
        thread_ptr->join(); // waits for all threads to finish
        thread_ptr->~thread();
    }
    
    sem_destroy(&sema);
}

/**
 * Requests thread pool to execute job by adding it to round robin queue
 */
void thread_pool::execute(thread_job *job)
{
    queue_lock.lock();
    queue.push_back(job);
    queue_lock.unlock();
    sem_post(&(sema)); // open up thread to execute task
}

void mysleep(void *arg)
{
    struct work_data *data = (struct work_data *)arg;
    printf("is working on job %u\n", data->work_id);
    fflush(stdout);
    sleep(data->time);
}

int main()
{
    thread_pool pool = thread_pool{2};
    std::vector<std::unique_ptr<thread_job>> jobList{}; // to keep job ptrs in scope of main, rather than just 1 iteration of for loop
    for (size_t i = 0; i < N_JOBS; i++)
    {
        std::unique_ptr<thread_job> job{new thread_job{mysleep, new work_data{1, (uint32_t)i}}};
        jobList.emplace_back(std::unique_ptr<thread_job>{job.release()});
        pool.execute(jobList[jobList.size()-1].get()); // pool does not own job, main owns job (so we can get results afterwards)
    }
    sleep(MAIN_THREAD_TIMEOUT);
    puts("Finishing up now!");
    return 0;
    // At this point jobList's unique_ptr's destructuros are called, freeing all thread jobs,
    // Then thread pool destructor is called to join threads.
}