void init_scheduler() {

}

void start_scheduler() {
    while (1){
        struct process *p = nex_process();
        switch_to(p);
    }
}

