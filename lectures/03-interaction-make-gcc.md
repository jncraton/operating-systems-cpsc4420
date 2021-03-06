1.7 Supporting Interactions Across Time
=======================================

Storage
-------

- OS provides long-term storage for computation results
- Results can be retrieved for future computations

File system
-----------

- Named persistent storage
- Typically organized in a hierarchy

File access
-----------

- Accessed via OS APIs (`read`, `write`)
- May be mapped to memory space and accessed directly with `load` and `store`

Databases
---------

- Provide persistent storage
- Allows related data to be access easily

---

What if the system goes down during a write?

Crashes
-------

- Any operation should be immediately interruptable without leaving persistent storage in a degraded state
- Atomic transactions and journaling may be a solution to this

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

Make and GCC
============

GCC
---

- [GNU Compiler Collection](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)
- Main compiler, linker, and assembler used for this class
- Free and open source optimizing compiler produced by the [GNU project](https://en.wikipedia.org/wiki/GNU_Project)

What is GCC
-----------

- Just a program

```sh
> which gcc
/usr/bin/gcc
```

How to use GCC
--------------

- Run it
- Enter `/usr/bin/gcc` in the shell. If the location of gcc is in your `PATH`, you can simply type `gcc` and the OS will resolve the full path.

```sh
> gcc
gcc: fatal error: no input files
compilation terminated.
```

Compiling Files
---------------


Compile source files into executable

```
> gcc src1.c src2.c --output executable
```

Hello, world
------------

hello.c:

```c
#include <unistd.h>

int main() {
  write(0, "Hello, world!\n", 14);
  return 0;
}
```

Compile
-------

Preprocess, compile, assemble, and link our program to the file `hello`

```sh
> gcc hello.c --output hello
```

Run
---

We now have a new executable file. We can run it in the shell as:

```sh
> ./hello
```

More advance operations
-----------------------

Compile source code into Assembler instructions:

```sh
> gcc -S src.c
```

Compile source code without linking:

```sh
> gcc -c src.c
```
