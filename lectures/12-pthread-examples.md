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

---

![CIA Triad](https://www.nist.gov/sites/default/files/images/2022/09/09/cyber-triad-1.png){height=540px}

2 Threads
=========

2.2 Example Multi-threaded Program
==================================

---

- [Multi-threaded C Program](../examples/2-simple-thread/threads.c)
- [Multi-threaded C Program with thread arguments](../examples/2-simple-thread/thread-args.c)
