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
