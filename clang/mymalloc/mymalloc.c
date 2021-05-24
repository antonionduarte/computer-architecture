#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BLOCK_SIZE sizeof(struct s_block)

typedef struct s_block *t_block;

struct s_block {
    size_t size;  // current size of block
    t_block next; // pointer to next block
    int free;     // flag indicating that the block is free or occupied; 0 or 1.
};

t_block head = NULL; // points to the beginning of the list
t_block tail = NULL; // points to the last element of the list

t_block find_block(size_t size) {
    t_block b = head;
    // TODO: alterar para best-fit
    while (b != NULL && !(b -> free && b -> size >= size))
        b = b->next;
    return b;
}

t_block extend_heap(size_t s) {
    t_block b = sbrk(BLOCK_SIZE+s);
    if (b == (void *) -1)
        return NULL; /* if sbrk fails, return NULL pointer*/

    b -> size = s;
    b -> next = NULL;
    b -> free = 0;

    if (head == NULL) head = b;
    else tail -> next = b;

    tail = b;
    return b;   // with metadata
}

void debugBlockList() {
    t_block p = head;
    printf("current block list:\n");

    while (p != NULL) {
        printf("address: %lu - %u bytes (%s)\n",
           (unsigned long)(p+1), p -> size, p -> free ? "free" : "in use");
        p = p -> next;
    }
}


void* myMalloc(size_t size) {
    if (size == 0) return NULL;

    t_block block = find_block(size);

    if (block == NULL) block = extend_heap(size);

    if (block == NULL) return NULL; // sbrk failed

    block -> free = 0;

    return block + BLOCK_SIZE; 
}

void myFree(void *ptr) {
    if (ptr != NULL) {
        t_block block = ptr - BLOCK_SIZE;
        block -> free = 1;
    }
}

/**
 * teste myMalloc/myFree
 **/
int main(int argc, char *argv[]) {
    unsigned int maxSpace;

    if (argc != 2) {
        printf("%s max_memory_to_allocate\n", argv[0]);
        exit(1);
    }
    maxSpace = atoi(argv[1]);

    printf("\nPERSONAL TESTS:\n");
    void* ptr = myMalloc(2);
    printf("%lu\n", (unsigned long) ptr);
    debugBlockList();
    myFree(ptr);
    debugBlockList();
    printf("\n");

    printf("Metadata size=%d\n", BLOCK_SIZE);
    // getting the current break value
    printf("Current program break = %lu\n", (unsigned long)sbrk(0));

    for (int s = 1; s < maxSpace; s *= 2) {
        void *ptr = myMalloc(s);
        if (ptr == NULL)
            printf("No more mem\n");
        else
            printf("returned pointer = %lu\n", (unsigned long)ptr);
        myFree(ptr);
    }
    debugBlockList();
    // getting the current break value
    printf("Current program break = %lu\n", (unsigned long)sbrk(0));
    for (int s = 1; s < maxSpace; s *= 2) {
        void *ptr = myMalloc(s);
        if (ptr == NULL)
            printf("No more mem\n");
        else
            printf("returned pointer = %lu\n", (unsigned long)ptr);
    }
    debugBlockList();

    return 0;
}
