#include <stdint.h>
#include <unistd.h>

struct thread_data;
struct thread_pool;
struct thread_job;
struct thread_job *thread_job_new(void (*fn)(void *), void *data);
void thread_job_destroy(struct thread_job *j);
void *thread_pool_work(void *arg);
struct thread_pool *thread_pool_new(size_t n);
void thread_pool_execute(struct thread_pool *pool,
                         struct thread_job *job);
void thread_pool_destroy(struct thread_pool *pool);


struct thread_pool{
    bool alive{true};
    std::mutex queue_lock{};
    std::deque<thread_job*> queue{};
    std::unordered_map<std::thread*, bool> thread_available{};
    sem_t sema; 
    int size;

    thread_pool(size_t n);

    ~thread_pool();

    /**
     * Requests thread pool to execute job by adding it to round robin queue
    */
    void execute(thread_job* job);
};