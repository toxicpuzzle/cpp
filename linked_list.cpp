#include <stdlib.h>
#include <iostream>

/**
 * Represents a node data structure used for constructed the LL
 */
struct node
{
    node *next;
    node *prev;
    int content;
};

/**
 * Represents a linked list data structure for ints
 */

struct linked_list
{
    node *head;
    int size;
};

linked_list *create_list()
{
    linked_list *list = (linked_list *)malloc(sizeof(linked_list));
    list->head = (node *)malloc(sizeof(node)); // head is null node placeholder
    list->size = 0;
    return list;
}

void insert_before(linked_list *list, int index, int value)
{
    node *cursor{list->head};
    node *newNode{(node *)malloc(sizeof(node))};
    newNode->content = value;
    for (int i = 0; i < index; i++)
    {
        cursor = cursor->next;
    }
    node *oldNext = cursor->next;
    cursor->next = newNode;
    newNode->prev = cursor;
    newNode->next = oldNext;
    if (oldNext != nullptr)
    {
        oldNext->prev = newNode;
    }
    list->size++;
}

node *get_node(linked_list *list, int index)
{
    node *cursor{list->head};
    for (int i = 0; i <= index; i++)
    {
        cursor = cursor->next;
    }
    return cursor;
}

void append(linked_list *list, int value)
{
    node *newNode{(node *)malloc(sizeof(node))};
    node *tail = get_node(list, list->size - 1);
    tail->next = newNode;
    newNode->prev = tail;
    newNode->content = value;
    list->size++;
}

int get(linked_list *list, int index)
{
    return get_node(list, index)->content;
}

void print_list(linked_list *list)
{
    for (int i = 0; i < list->size; i++)
    {
        std::cout << get(list, i) << "\n";
    }
}

void remove(linked_list *list, int index)
{
    node *toRemove = get_node(list, index);
    node *before = toRemove->prev;
    node *after = toRemove->next;

    before->next = after;
    if (after != nullptr)
    {
        after->prev = before;
    }
    free(toRemove);

    list->size--;
}

int main(int argc, char const *argv[])
{
    linked_list *list = create_list();
    append(list, 1);
    append(list, 10);
    append(list, 2);
    append(list, 5);
    append(list, 7);

    insert_before(list, 0, 2);
    insert_before(list, list->size - 1, 2);

    remove(list, 2);

    print_list(list);
    return 0;
}
