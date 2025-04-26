#include "scheduler.h"
#include "process.h"
#include <stddef.h>

static process *current = NULL;
static process *head = NULL;

void add_scheduler(struct process *proc) {
    if (!head){
        head = proc;
        proc->next=proc;
    } else {
        proc->next = head->next;
        head->next = proc;
    }
}

void init_scheduler() {
    current = head;
}

void start_scheduler() {
    while (1) {
        if (current){
            current->entry_point();
            current = current->next;
        }
    }
}

