#include "memory.h"
#include <stdint.h>

#define KERNEL_HEAP_START 0x1000000
#define KERNEL_HEAP_SIZE  0x100000

static uint8_t* heap_start = (uint8_t*) KERNEL_HEAP_START;
static uint8_t* heap_end   = (uint8_t*) (KERNEL_HEAP_START + KERNEL_HEAP_SIZE);
static uint8_t* heap_curr  = (uint8_t*) KERNEL_HEAP_START;


void init_memory() {
    heap_curr = heap_start;
}

void* kmalloc(size_t size) {
    if (heap_curr + size > heap_end) {
        return NULL;
    }

    void* block = heap_curr;
    heap_curr += size;
    return block;
}

void kfree(void* ptr) {
    (void)ptr;
}