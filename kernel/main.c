#include "scheduler.h"
#include "memory.h"
#include "ipc.h"

void proc1() {
    for (;;) *(char*)(0xb8000) = 'A';
}

void proc2() {
    for (;;) *(char*)(0xb8002) = 'B';
}

void kernel_main(){
    init_memory();

    static process p1, p2;

    p1.pid = 1;
    p1.entry_point = proc1;
    p1.stack = kmalloc(4096);

    p2.pid = 2;
    p2.entry_point = proc2;
    p2.stack = kmalloc(4096);
    
    scheduler_add(&p1);
    scheduler_add(&p2);

    scheduler_init();
    scheduler_start();

    //void* bloque1 = kmalloc(128);
    //void* bloque2 = kmalloc(64);
}