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
to transfer amount from sourceAccount to destinationAccount:
  lock sourceAccount.mutex
  lock destinationAccount.mutex
  sourceAccount.balance = sourceAccount.balance - amount
  destinationAccount.balance = destinationAccount.balance + amount
  unlock sourceAccount.mutex
  unlock destinationAccount.mutex
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
to transfer amount from sourceAccount to destinationAccount:
  lock min(sourceAccount, destinationAccount).mutex
  lock max(sourceAccount, destinationAccount).mutex
  sourceAccount.balance = sourceAccount.balance - amount
  destinationAccount.balance = destinationAccount.balance + amount
  unlock sourceAccount.mutex
  unlock destinationAccount.mutex
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
