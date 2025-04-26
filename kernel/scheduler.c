#include "scheduler.h"
#include "process.h"
#include <stddef.h>

static process *current = NULL;
static process *head = NULL;

void scheduler_add(struct process *proc) {
    if (!head){
        head = proc;
        proc->next=proc;
    } else {
        proc->next = head->next;
        head->next = proc;
    }
}

void scheduler_init() {
    current = head;
}

void scheduler_start() {
    while (1) {
        if (current){
            current->entry_point();
            current = current->next;
        }
    }
}

