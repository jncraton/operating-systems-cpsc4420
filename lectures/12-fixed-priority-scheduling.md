3.4 Fixed-priority scheduling
-----------------------------

Priority
--------

- Number assigned to each thread
- May be assigned by a user and not adjusted automatically by the OS
- Note that higher priorities may be represented by lower numbers

Scheduling
----------

- The runnable thread with the highest priority will be run next

Advantages
----------

- Incredibly simple
- Can help meet some limited user needs

---

What are some weaknesses of fixed-priority scheduling?

Implementation
--------------

- Priority queue
- Most simply, a list of threads for each priority level

Ties
----

- Option 1 - Keep running the current thread (FIFO)
- Option 2 - Cycle highest priority thread in round-robin fashion (RR)

FIFO
----

- Allow the thread to complete it's work fastest
- Does not allow any other high priority threads to run

RR
---

- Allow all highest priority threads to run
- Delays work on one thread to service others

Niche
-----

- A busy high priority thread will consume all system resources
- In a carefully controlled system, they can be useful

Hard-real-time systems
----------------------

- Data and computation must be completed on a fixed timetable
- Aircraft
- Control systems
- [Rockets](https://www.youtube.com/watch?v=pmRrnyDssZc&t=360s)

---

Gantt Charts and Examples