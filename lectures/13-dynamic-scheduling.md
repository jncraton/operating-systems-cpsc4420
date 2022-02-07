3.5 Dynamic Priority Scheduling
===============================

Priority based scheduling
-------------------------

- Useful in limited circumstances
- Helpful as a framework for more advanced scheduling
- What if the OS could automatically adjust priorities?

Earliest Deadline First
-----------------------

- Useful in real-time applications with deadlines
- Assign highest priority to thread with the earliest deadline
- Improves upon rate-monotonic scheduling

Example Processes
-----------------

Process  Execution Time  Period
-------  --------------  ------
P1       1               8
P2       2               5
P3       4               10 

---

![Example schedule](https://upload.wikimedia.org/wikipedia/commons/thumb/3/3f/EDF_Example_Timing_Diagram.png/800px-EDF_Example_Timing_Diagram.png)

Decay Usage Scheduling
----------------------

- Suitable for systems with deadlines
- Lower priority for threads that run more
- Allows quick, interactive tasks to execute instantly while moving compute-intensive tasks to the background

Insert figure 3.9

3.6 Proportional Share Scheduling
=================================

Fairness
--------

- Equal sharing of resources my be more important than other factors

...
