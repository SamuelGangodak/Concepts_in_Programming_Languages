# include<stdio.h>
# include<stdlib.h>
# include<stdbool.h>

typedef struct Node{
    size_t block_size;
    bool isAllocated;
    struct Node *next;
    struct Node *prev;
}meta_Data;
 
struct metadata{
    meta_Data *head;
}MetaList;

char Heap[1024];

void use_heap();

void printFreeList();

void* allocate_memory(size_t mem);

void merge(meta_Data **head);

void free_memory(void *ptr);

void return_heap();