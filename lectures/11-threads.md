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
