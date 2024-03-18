4.4 Other Synchronization Patterns
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

- Provides storage space for producer output
- Limited in space because space is finite and larger size produces diminishing returns
- When buffer is empty, consumer must wait
- When buffer is full, producer must wait

---

![Bounded burger buffer](media/4-14.png)
