#include "scheduler.h"
#include "memory.h"
#include "ipc.h"

void kernel_main(){
    init_memory();
    
    void* bloque1 = kmalloc(128);
    void* bloque2 = kmalloc(64);

    init_scheduler();
    init_ipc();
    start_scheduler();
}