# include<stdio.h>
# include"heap.h"

void use_heap() {
    MetaList.head=(void*)Heap; 
    MetaList.head->block_size=1024;
    MetaList.head->isAllocated=false;
    MetaList.head->next=NULL;
    MetaList.head->prev=NULL;
}

void printFreeList() {
    meta_Data *curr=MetaList.head;
    while(curr!=NULL) {
        printf("%d\t%x\t", curr->block_size, curr);
        if(curr->isAllocated) {
            printf("Allocated\n");
        }
        else {
            printf("free\n");
        }
        curr=curr->next;
    }
    printf("\n\n");
}

void* allocate_memory(size_t mem) {
    meta_Data *node=MetaList.head;
    void *ret_val=NULL;
    size_t req_size=mem+sizeof(meta_Data);
    if(node==NULL) {
        printf("Heap memory is inaccessible\n");
    }
    else {
        while(node!=NULL && (node->isAllocated||(node->block_size)<req_size) ) {
            node=node->next;
        }
        if(node==NULL) {
            printf("Not much continuous space to allocate memory\n\n");
        }
        else if((node->block_size)>req_size) {
            meta_Data *temp=(void*)(node+req_size);
            temp->block_size=(node->block_size)-req_size;
            temp->isAllocated=false;
            temp->next=node->next;
            if(temp->next!=NULL) {
                temp->next->prev=temp;
            }
            temp->prev=node;
            *(node+req_size)=*temp;
            node->block_size=req_size;
            node->next=temp;
            node->isAllocated=true;
            ret_val=node+1;
        }
        else {
            node->isAllocated=true;
            ret_val=node+1;
        }
    }
    return ret_val;
}

void merge(meta_Data **head) {
    if((*head)->next!=NULL && (*head)->next->isAllocated==false) {
        meta_Data *temp=(*head)->next;
        (*head)->block_size+=temp->block_size;
        (*head)->next=temp->next;
        if((*head)->next!=NULL) {
            (*head)->next->prev=(*head);
        }
    }
    if((*head)->prev!=NULL && (*head)->prev->isAllocated==false) {
        meta_Data *temp=(*head);
        (*head)=(*head)->prev;
        (*head)->block_size+=temp->block_size;
        (*head)->next=temp->next;
        if((*head)->next!=NULL) {
            (*head)->next->prev=(*head);
        }
    }
}

void free_memory(void *ptr) {
    meta_Data* curr=(meta_Data*)((ptr)-sizeof(meta_Data));
    (curr)->isAllocated=false;
    merge(&curr);
    printf("freed\n\n");
}

void return_heap() {
    MetaList.head=NULL;
}
