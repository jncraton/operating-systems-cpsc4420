# 4.8 Interaction of Synchronization and Scheduling

## Synchronization and Scheduling

- Scheduler determines which thread to run
- Synchronization actions performed by running threads determine which other threads are runnable

## Priority Inversion

- Causes lower priority threads to be favored over higher priority threads
- Can occur when threads of different priorities share a mutex

## Short-term example

1. High priority thread waits on I/O
2. Low priority runs and acquires mutex
3. I/O completes and the high priority thread preempts the other
4. High priority thread can't acquire mutex
5. Low priority thread resumes

## Short term issues

- Generally not a significant problem
- Concurrent algorithms should be designed to only briefly hold a mutex
- High priority thread will resume promptly

## Problematic Example

1. High and medium threads both wait on I/O
2. Low priority thread runs and acquires mutex
3. All I/O completes and the high priority thread preempts the others
4. The high priority thread cannot acquire the mutex and waits
5. The medium priority thread runs and the low priority thread is unable to give up the mutex

## Possible Solution

- Boost priority of lower priority threads that haven't run much (e.g. decay usage scheduler)
- Creates problems on real-time systems where fixed priorities are desired

## Priority Inheritance

- A lower priority thread borrows the higher priority of a thread that is waiting on it
- Similar ideas can be applied to other schedulers

## Convoy Phenomenon

- A popular mutex may constantly be contested among a number of threads
- This creates a "convoy" of threads in the waiting queue

## Convoy Issues

- Increased context switching due to most lock operations requiring a context switch
- Decreased throughput due to increase context switching
- Breakdown of scheduler prioritization as many threads are not runnable
- Mutex wait queue manages scheduling in practice

## Solution

- Integrate the mutex wait queue with the scheduler and avoid simple FIFO behavior
- Allow a high-priority thread to relock a mutex it gives up even if other threads are waiting on it

# 4.10 Security and Synchronization

## Policy vs Practice

- Some security flaws are due to improper policies implemented correctly
- Other flaws may be due to correct policies with buggy implementations

## Synchronization Bugs

- Concurrency is hard, so programmers are likely to introduce bugs
- Race conditions are hard to test for, as the system will usually perform correctly
- Crackers may be able to induce race conditions more frequently than would naturally occur
- Race conditions can allow "impossible" situations and break through defenses

## Time of check to time of use

- Class of bugs
- Involve checking for some condition and then using it in a concurrent system
- If the value changes between these points, security assumptions can be violated
