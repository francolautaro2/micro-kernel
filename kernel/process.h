typedef struct process {
    int pid;
    void (*entry_point)();
    uint8_t *stack;
    struct process *next;
} process;