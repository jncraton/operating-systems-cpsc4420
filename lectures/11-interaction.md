1.6 Controlling Interactions Between Computations
=================================================

Dependencies
------------

- Sometimes threads are not fully independent
- One thread may generate data that another consumes
- These threads need to interact via *synchronization*

---

What if thread A is waiting for thread B and thread B is waiting for thread A?

Deadlock
--------

- Cyclic waiting
- Must be addressed to prevent freezes
- Difficult to solve generally

Transaction
-----------

- Unit of computation with no externally visible internal state
- Computation succeeds for fails as a unit
- Useful concurrency primitive

Accidental Interaction
----------------------

- Threads share memory, so they may interact unintentionally
- This can be mitigated on some systems using virtual memory

1.7 Supporting Interactions Across Time
=======================================

Storage
-------

- OS provides long-term storage for computation results
- Results can be retrieved for future computations

File system
-----------

- Named persistent storage
- Typically organized in a hierarchy

File access
-----------

- Accessed via OS APIs (`read`, `write`)
- May be mapped to memory space and accessed directly with `load` and `store`

Databases
---------

- Provide persistent storage
- Allows related data to be access easily

---

What if the system goes down during a write?

Crashes
-------

- Any operation should be immediately interruptable without leaving persistent storage in a degraded state
- Atomic transactions and journaling may be a solution to this
