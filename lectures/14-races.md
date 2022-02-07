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