#include "scheduler.h"
#include "memory.h"
#include "ipc.h"

void kernel_main(){
    init_memory();
    init_scheduler();
    init_ipc();
    start_scheduler();
}