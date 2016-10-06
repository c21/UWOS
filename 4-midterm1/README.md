# Review for midterm 1
1. Processor will
    * fetch instruction from memory
    * decode
    * execute

2. OS is the software to make system easy to use.
    * (virtual machine, standard library, resource manager)

3. Process
    * It's running program.
    * It contains machine state: memory, registers (PC/IP,SP...), I/O information.
    * Running a process: load code/data into memory, create stack, set up I/O.
    * Running many processes: time sharing of CPU.
    * APIs:
        * fork(): create another process (copy address space)
        * wait(): wait for child process to finish
        * exec(): run another program in this process (initialize address space)
        * kill(): send signal to process
        * shell run command: fork then redirection and so on, then exec

4. Schedule of processes
    * mechanism: limited direct execution:
        1. restrict operation
            * user mode, kernel mode
            * system call: The API OS provides. It will transfer the control to the OS
                   to do privileged operations (user mode->kernel mode).
                   process -> OS trap handler (trap instruction)
                   OS -> process (return-from-trap instruction)
        2. switch processes
            * time interrupt
                * process -> OS interrupt handler (time is over)
        OS -> (maybe another) process (return-from-trap instruction)
            * context switch (switch processes)
                * save registers on its kernel stack, restore another process's registers
        * Process traps in OS, and OS context switches process, both save registers on its kernel stack.
    * policy:
        * turnaround time: T(process finishes) - T(process arrives)
        * response time: T(process first runs) - T(process arrives)
        1. first in, first out (FIFO)
            * suffer from short-term process waiting for long-term process
        2. shortest job first (SJF)
            * run current shortest job and finish it
            * suffer from short-term process waiting for long-term process
        3. shortest time-to-completion first (STCF)
            * when any new job arrives, run the one has shortest time to finish
            * suffer from long response time for some processes
            * good for turnaround time
        4. round robin (RR)
            * run each process within a time slice
            * suffer from long turnaround time for all processes
            * good for response time
        5. multi-level feedback queue (MLFQ)
            1. first put process at highest level queue (assume all processes are short term)
            2. round robin processes at highest level queue (give good response time)
            3. when process uses up CPU time at one level, decrease to next level queue (short-term->long-term)
            4. after some time, move all processes to the highest level queue (avoid starvation)
            * make effort to decrease turnaround and response time, with no knowledge of execution time of job

5. Memory of processes
    * mechanism: address translation:
        1. base and bounds
            * base register: start address of process's physical memory
            * bound register: the size of process's physical memory
            * when address translation fault, generate exception to let OS handler to handle
            * HW: use registers to translate address
            * OS: set up registers, handle exception, allocate/deallocate physical memory
            * suffer from inefficient memory use, internal fragmentation (lots of memory unused inside of memory: stack,heap)
        2. segmentation
            * chop up process's address space into several segments (e.g.code,stack,heap...), for each segment, use base and bounds
            * need a bit to indicate the memory grow positive or negative (for stack)
            * HW can use top bits of virtual address to choose which registers to use
            * suffer from generating many small free memory space, external fragmentation (segments no longer same size)
            * good for avoiding internal fragmentation
        3. paging
            * chop up process's address space into same size pages
            * page table: virtual page number (VPN) -> physical frame number (PFN) for each page table entry(PTE)
                * valid bit: whether this virtual page is in use
                * present bit: whether this physical page is in memory
                * protection bit, dirty bit, reference bit.
            * page table base register (PTBR): the start physical address of page table
            * page table is too large to sit in MMU, so it is in memory (space issue)
            * require extra memory reference to get physical frame number from page table (time issue)
            * one extra memory reference for each instruction fetch, for each instruction which reads/writes to memory
            
            1. time issue: translation lookaside buffer(TLB)
                * translate a virtual page number, first look up TLB (in MMU)
                * valid bit: whether this TLB entry is a valid translation (!= page table valid bit)
                * address space identifier: similar to PID, indicate which process owns this entry
                * handle TLB miss: 1.HW (HW knows format of page table) 2.OS (HW raises exception)

            2. space issue:
                1. combine paging and segmentation
                    * for each segment, maintain page tables, don't allocate page table entry for unused address space
                    * base register: the start address of segment's page table
                    * bound register: the valid size of page table
                    * suffer from sparse-used address space (heap), external fragmentation to allocate page tables
                2. multi-level page tables
                    * chop up page table into same size pages, don't allocate page table entry for unused page
                    * use page directory to point to valid page of page table
                    * page directory: page frame number of page of page table
                        * valid bit: indicate at least one of pages of page table is valid
                    * suffer from more than one extra memory reference
                    
            * swap page between memory and disk:
                * swap space: the space on disk for swapping pages
                * page fault: find a page not in physical memory when doing address translation, let OS handle page fault (disk address stored in page table entry)
                * page replacement policy:
                    1. replace the page will be used furthest in the future (optimal)
                        * don't know the knowledge of future use
                    2. replace the page coming into memory earliest (FIFO)
                        * suffer from replacing important page
                    3. randomly replace a page (random)
                        * suffer from replacing important page
                    4. replace page least recently used(LRU)
                        * suffer from hard to implement (time complexity)
                    5. clock algorithm (approximate LRU)
                        * use bit: for each page, set to 1 when page is referenced
                        * When replcement, start from one page, check use bit. If 1, set to 0. If 0, replace this page.

    

