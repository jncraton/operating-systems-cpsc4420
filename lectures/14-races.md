4.2 Races and the Need for Mutual Exclusion
===========================================

Races
-----

- Two threads may be operating concurrently in an unsyncronized manner
- This can lead to output that differs over different program runs
- This may lead to bugs or unexpected behavior

Example
-------

```c
if(seatsRemaining > 0){
  dispenseTicket();
  seatsRemaining = seatsRemaining - 1;
} else {
  displaySorrySoldOut();
}
```

---

Can the example sell more tickets than are available?

---

What if it is running in multiple threads?

---

[examples/race/tickets.c](../examples/race/tickets.c)

Core Issue
----------

- Multiple threads operating on the same data structure with interleaving modifications

Solution
--------

- Allow only one thread to access the data at a time
- Sometimes referred to as locking the data structure
- This creates mutual exclusion (mutex)

Thread Safe Operations
---------------

- Only reading from the same data structure
- Interleaving operations without data dependencies
- Interleaving atomic operations
