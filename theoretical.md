[link](https://leetcode.com/discuss/study-guide/2272161/most-important-topics-for-interviews-cs-core-topics)
## Important Topic for OS

## `Process (Attributes, state, life cycle, PCB) vs Thread.`

- `Process`: Processes are basically the programs that are dispatched from the ready state and are scheduled in the CPU for execution. PCB(Process Control Block) holds the concept of process. A process can create other processes which are known as Child Processes. The process takes more time to terminate and it is isolated means it does not share the memory with any other process. The process can have the following states new, ready, running, waiting, terminated, and suspended.
- `Thread`: Thread is the segment of a process which means a process can have multiple threads and these multiple threads are contained within a process. A thread has three states: Running, Ready, and Blocked. The thread takes less time to terminate as compared to the process but unlike the process, threads do not isolate.

| Process                                                                             | Thread                                                                                                                                                                       |
| ----------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Process means any program is in execution.                                          | Thread means a segment of a process.                                                                                                                                         |
| It takes more time for creation.                                                    | It takes less time for creation.                                                                                                                                             |
| It also takes more time for context switching.                                      | It takes less time for context switching.                                                                                                                                    |
| The process is less efficient in terms of communication.                            | Thread is more efficient in terms of communication.                                                                                                                          |
| Multiprogramming holds the concepts of multi-process.                               | We don’t need multi programs in action for multiple threads because a single process consists of multiple threads.                                                           |
| The process is isolated.                                                            | Thread shares memory.                                                                                                                                                        |
| The process is called the heavyweight process.                                      | A Thread is lightweight as each thread in a process shares code, data, and resources.                                                                                        |
| Process switching uses an interface in an operating system.                         | Thread switching does not require calling an operating system and causes an interrupt to the kernel.                                                                         |
| If one process is blocked then it will not affect the execution of other processes. | If a user-level thread is blocked, then all other user-level threads are blocked.                                                                                            |
| The process has its own Process Control Block, Stack, and Address Space.            | Thread has Parents’ PCB, its own Thread Control Block, and Stack and common Address space.                                                                                   |
| Changes to the parent process do not affect child processes.                        | Since all threads of the same process share address space and other resources so any changes to the main thread may affect the behavior of the other threads of the process. |
| A system call is involved in it.                                                    | No system call is involved, it is created using APIs.                                                                                                                        |
| The process does not share data with each other.                                    | Threads share data with each other.                                                                                                                                          |

## `Scheduling Algorithms`

- `Preemptive Scheduling`: Preemptive scheduling is used when a process switches from running state to ready state or from the waiting state to the ready state.
- `Non-Preemptive Scheduling`: Non-Preemptive scheduling is used when a process terminates , or when a process switches from running state to waiting state.

- Multiprogramming vs Multiprocessing vs Multitasking vs Multithreading.

- Memory Allocation

- Fixed Partioning
- Dynamic Partioning
- Paging
- Segmentation
- Internal and External Fragmentation.

- Memory Allocation Technique.

- Page replacement Algos

- Deadlock

- Critical section problem

- Benefits of a multiprocessor system

- RAID structure in OS and different levels of RAID Configration.

- Bootstrap program in OS

- Demand paging

- RTOS

- IPC

- Main Memory Vs Secondary Memory

- Mutex vs Semaphore