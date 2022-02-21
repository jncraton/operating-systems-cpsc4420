Exam 1 - Wednesday, March 2

4.4 Other Syncronization Patterns
=================================

Producer-consumer model
-----------------------

- One thread produces data consumed by another thread
- Can be implemented sequentially
- Can be implemented as threads that wait on one another, but with limited concurrency

Concurrency
-----------

- Producer and consumer run at the same time
- Producer creates output and stores it
- Consumer grabs input as needed from storage

Bounded Buffer
--------------

- Provices storage space for producer output
- Limited in space because space is finite and larger size produces diminishing returns
- When buffer is empty, consumer must wait
- When buffer is full, producer must wait

---

![Bounded burger buffer](media/4-14.png)

Pipes
-----

- Provide OS-level support for bounded buffers between processes
- `du | sort -n`

Readers/Writers Locks
---------------------

- Alternative to mutex
- Allows lock to specify whether thread is reading or writing
- Only one writer may access the mutex at a time, but multiple readers are allowed

---

![Readers/Writers Lock](media/4-15.png)

Barriers
--------

- Requires multiple concurrent threads to finish a task before moving on
- Similar to our use `pthread_join`, but does not require threads to terminate

4.5 Condition Variables
=======================
