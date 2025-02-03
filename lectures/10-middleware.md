1.3 Middleware
==============

Middleware
----------

- Middleware is software that sits between application programs and the operating system
- Databases, Runtimes, etc

---

![Middleware](media/1-2.png)

1.5 Multiple Computations on One Computer
=========================================

Resources
---------

- Limited CPU time, disk access bandwidth, memory bandwidth
- Multiple applications using resources simultaneously

Concurrency
-----------

- Make efficient use of resources
- When we aren't actively using the CPU because we are waiting on I/O, another program can use it

Thread
------

- Fundamental unit of concurrency
- Sequence of programmed actions
- Each program includes at least one thread

Process
-------

- Container for one or more threads
- Protects threads from interactions from unrelated threads running on the same computer
- Threads in different processes do not share memory

---

![Process with 2 threads](https://upload.wikimedia.org/wikipedia/commons/a/a5/Multithreaded_process.svg)

Thread APIs
-----------

- Create 
- Kill
- Switch

Scheduling
----------

- OS will have many threads that can be run
- Limited CPUs are available
- OS must select thread to run
