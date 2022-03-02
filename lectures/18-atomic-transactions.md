- Exam Results

Atomic Transactions
===================

Invariant
---------

- Property of a mathematical object
- Holds true after certain classes of operations

Monitor objects
---------------

- Preserve invariants using mutexes for public methods
- Interleaving is not allowed, so object state is always consistent

---

What if invariants span multiple objects?

---

Rooted Tree
-----------

- Tree data structure
- Pointers from parent to child
- Pointers from child to parent

---

![Rooted Tree Example](media/5-1.png)

Atomic Tranaction
-----------------

- Operation that transition a system from one observable state to another
- No intermediate states are visible
- State maintains consistency across transactions
- Often simply referred to as transactions

Atomicity
---------

- Entire transaction succeeds or fails
- State is always consistent

Durability
----------

- A completed transaction will be reflected in the system state even if the system crashes

5.3 Atomic Transaction Mechanisms
=================================

Guarantees
----------

- Current transactions are isolated from one another
- Failed transactions have no visible effects

Serializability
---------------

- Concurrent transactions may execute simultaneously as long as they do not interfere
- They must execute as if running serially
- Execution that is equivalent to serial executions is called serializable