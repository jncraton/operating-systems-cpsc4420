2.1 Introduction to Threads
===========================

Thread
------

- A sequence of computational instructions run one after another

Single-threaded Programs
------------------------

- Simple programs typically have only one thread
- Many programs you have written fall into this category
- They are easy to reason about and understand

Multi-threaded Programs
-----------------------

- Contain multiple threads of execution
- Are suitable for parallel processing tasks
- Make effective use of modern computer architectures

---

![AMD Threadripper CPU](https://upload.wikimedia.org/wikipedia/commons/3/35/AMD_Threadripper.svg){height=540px}

Programs and Threads
--------------------

- Programs are a collection of instructions
- A thread is a collection of instructions being executed
- Every running program has at least one thread

---

Process
-------

- Most operating systems implement a container to hold threads
- This container is called a process

---

![Multi-threaded process](https://upload.wikimedia.org/wikipedia/commons/a/a5/Multithreaded_process.svg)

Lifetime
--------

- Threads exist from the time their first instruction begins executing until the time of last instruction execution
- Threads with overlapping lifetimes are running concurrently
- A key feature of most operating systems is allow threads to run concurrently
