1.8 Supporting Interactions Across Space
========================================

Networking
----------

- Provides a means for separate systems to interact
- Network stack organized into layers

Sockets
-------

- Provides a standard and consistent API for applications to use for networking
- Supports streaming and packet-based communication

Socket types
------------

- Stream - provides a virtual circuit
- Datagram - delivers individual packets

Socket Implementation
---------------------

- Independent of network type
- Most typically used with TCP/IP and UDP/IP

---

```c
if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
  return 1;
}

if( connect(sockfd, &serv_addr, sizeof(serv_addr)) < 0) {
  return 1;
}

if (n = read(sockfd, recvBuff, sizeof(recvBuff)-1)) <= 0) {
  return 1;
}

printf("%s\n", recvBuff);
```

1.9 Security
============

Threats
-------

- Operating systems need to be able to behave correctly in the face of malicious actors

Objectives
----------

- Confidentiality
- Integrity
- Availability
- Accountability

2 Threads
=========

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

2.2 Example Multi-threaded Program
==================================

---

- [Example program](../examples/2-simple-thread/threads.c)
- [Example program 2](../examples/2-simple-thread/thread-args.c)

2.3 Reasons for Concurrent Threads
==================================

---

Why is it desirable for the computer to execute multiple threads concurrently, rather than waiting for one to finish before starting another?

Responsiveness
--------------

- Allows rapid response to input even while working on other computations
- This is demonstrated by the example as both threads can respond to a timer

Resource Utilization
--------------------

- The computer has many hardware resources (CPU, memory, disks, etc)
- We want use all of these resources efficiently
- We need to be able to pause a thread waiting on I/O to allow the CPU to be used for other tasks

Modularization
-------------

- We may also like threads for creating cleaner programs
- Aspects of computation can be handled independently

Web Server Example
------------------

- What does a web server do?
- How might threads help?

---

![Web servers](media/2-5.png)

Multiprocessor Example
----------------------

- Nearly all systems now have multiple processors
- How are threads useful here?
- `make -j`
