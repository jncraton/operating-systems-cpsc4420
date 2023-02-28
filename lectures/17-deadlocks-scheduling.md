- Exam on Monday
- Lab questions?

4.7 Deadlocks
=============

Concurrency
-----------

- Addresses problems of responsiveness and throughput
- Creates problems with races
- Races can be resolved using synchronization patterns

---

What problems can be caused by synchronization?

Example
-------

```python
to transfer amount from srcAccount to dstAccount:
  lock srcAccount.mutex
  lock dstAccount.mutex
  srcAccount.balance = srcAccount.balance - amount
  dstAccount.balance = dstAccount.balance + amount
  unlock srcAccount.mutex
  unlock dstAccount.mutex
```

Analysis
---------

- Mutexes prevent race conditions
- Transfers will generally work correctly
- What if two accounts transfer to one another concurrently?

Deadlock
--------

- Each thread lock the first mutex and waits for the second
- They now have a circular dependency and will never progress or unlock their mutex

Deadlock conditions
-------------------

1. Threads hold resources exclusively
2. Threads hold some resources while waiting for others
3. Resources cannot be removed from threads by force
4. Threads wait in a circular chain

---

![Dining Philosophers](media/4-20.png)

Addressing Deadlocks
--------------------

- Prevention
- Detection and mitigation

Prevention Through Resource Ordering
------------------------------------

- Requires resources to have global IDs
- When locking resources, lock them in order by ID

Example
-------

```python
to transfer amount from srcAccount to dstAccount:
  lock min(srcAccount, dstAccount).mutex
  lock max(srcAccount, dstAccount).mutex
  srcAccount.balance = srcAccount.balance - amount
  dstAccount.balance = dstAccount.balance + amount
  unlock srcAccount.mutex
  unlock dstAccount.mutex
```

Linux Scheduler Example
-----------------------

```c
static void double_rq_lock(struct rq *rq1, struct rq *rq2)
  __acquires(rq1->lock)
  __acquires(rq2->lock)
  {
  BUG_ON(!irqs_disabled());
  if (rq1 == rq2) {
    raw_spin_lock(&rq1->lock);
    __acquire(rq2->lock);
     /* Fake it out ;) */
    } else {
    if (rq1 < rq2) {
      raw_spin_lock(&rq1->lock);
      raw_spin_lock_nested(&rq2->lock, SINGLE_DEPTH_NESTING);
    } else {
      raw_spin_lock(&rq2->lock);
      raw_spin_lock_nested(&rq1->lock, SINGLE_DEPTH_NESTING);
    }
  }
}

```

Detection
---------

- OS stores additional information about mutexes
- Track which thread holds a mutex
- Record which mutex a thread is waiting for
- Use this graph to periodically check for cycles (deadlocks)

---

![Mutex Cycle indicating Deadlock](media/4-22.png)

Breaking the Deadlock
---------------------

- A thread can be rolled back to before it attempted the offending lock
- Most systems don't support rolling back threads
- Killing a thread is the typical solution

Immediate detection
-------------------

- If we detect deadlocks conditions when the last lock in the cycle is attempted, we can notify applications and they can choose to take appropriate action

4.8 Interaction of Synchronization and Scheduling
================================================

Synchronization and Scheduling
------------------------------

- Scheduler determines which thread to run
- Synchronization actions performed by running threads determine which other threads are runnable

Priority Inversion
------------------

- Causes lower priority threads to be favored over higher priority threads
- Can occur when threads of different priorities share a mutex

Short-term example
------------------

1. High priority thread waits on I/O
2. Low priority runs and acquires mutex
3. I/O completes an the high priority thread preempts the other
4. High priority thread can't acquire mutex
5. Low priority thread resumes

Short term issues
-----------------

- Generally not a significant problem
- Concurrent algorithms should be designed to only briefly hold a mutex
- High priority thread will resume promptly

Problematic Example
-------------------

1. High and medium threads both wait on I/O
2. Low priority thread runs and acquires mutex
3. All I/O completes and the high priority thread preempts the others
4. The high priority thread cannot acquire the mutex and waits
5. The medium priority thread runs and the low priority thread is unable to give up the mutex

Possible Solution
-----------------

- Boost priority of lower priority threads that haven't run much (e.g. decay usage scheduler)
- Creates problems on real-time systems where fixed priorities are desired

Priority Inheritance
--------------------

- A lower priority thread borrows the higher priority of a thread that is waiting on it
- Similar ideas can be applied to other schedulers

Convoy Phenomenon
--------------

- A popular mutex may constantly be contested among a number of threads
- This creates a "convoy" of threads in the waiting queue

Convoy Issues
-------------

- Increased context switching due to most lock operations requiring a context switch
- Decreased throughput due to increase context switching
- Breakdown of scheduler prioritization as many threads are not runnable
- Mutex wait queue manages scheduling in practice

Solution
--------

- Integrate the mutex wait queue with the scheduler and avoid simple FIFO behavior
- Allow a thread to relock a mutex it gave up during its time slice even though other threads are waiting on it

4.10 Security and Synchronization
================================

Policy vs Practice
------------------

- Some security flaws are due to improper policies implemented correctly
- Other flaws may be due to correct policies with buggy implementations

Synchronization Bugs
-------------------

- Concurrency is hard, so programmers are likely to introduce bugs
- Race conditions are hard to test for, as the system will usually perform correctly
- Crackers may be able to induce race conditions more frequently than would naturally occur
- Race conditions can allow "impossible" situations and break through defenses

Time of check to time of use
----------------------------

- Class of bugs
- Involve checking for some condition and then using it in a concurrent system
- If the value changes between these points, security assumptions can be violated
