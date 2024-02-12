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

2.4 Switching Between Threads
=============================

Switching
---------

- A single-threaded CPU can run only one thread at a time
- A multi-threaded CPU still supports a finite number of concurrent threads
- We need mechanism for moving execution from one thread to another

---

![Processor and Disk intensive tasks](media/2-6.png)

Pausing
-------

- Stop a sequence of instructions from running
- Start up again later
- Something else can use the CPU in between

Stopping Processes
------------------

- Stop the process:
    - `kill -STOP [pid]`
- Resume execution:
    - `kill -CONT [pid]`

New Instruction
---------------

- switchFromTo(currentThread, newThread)
- Instructs the CPU to move its execution from one thread to another

---

Thread A            Thread B
------------------- ---------
Instruction A1
Instruction A2
switchFromTo(A, B)
                    Instruction B1
                    Instruction B2
                    switchFromTo(B, A)
Instruction A3
Instruction A4

---

What does it mean to switch threads?

Consider:

- Instruction Pointer
- Stack Pointer
- Register Values

Changing Threads
----------------

- Store all required registers (IP, SP, data registers, etc)
- Update instruction pointer

Thread Control Block
--------------------

- TCB
- Kernel data structure for storing thread parameters
- Address of block may be used to identify threads (A and B in previous examples)

What about memory
-----------------

- Each thread's memory should remain accessible and largely unchanged after switching
- The stack should be preserved exactly
- The stack is pushed to hold thread state when switching just like when calling a function

Pseudocode
----------

```
  Push registers to outgoing thread's stack
  Store stack pointer in outgoing->sp
  Load stack pointer from next->sp
  Store `restore` address into outgoing->ip
  Jump to next->ip
restore:
  pop registers from the now resumed outgoing thread
```

---

![Saving registers and per-thread stack](media/2-8.png)

Security
--------

- On most systems, memory protections are enforced
- A process can't jump into another processes memory
- The user mode thread switching described is not possible in practice

Kernel
------

- The kernel must be responsible for thread management and switching

Yield
-----

- Simplified version of `switchFromTo`
- Take no parameters
- Informs the kernel that the current thread is ready to take a break

Yield Implementation
--------------------

```
outgoing = current
next = chooseNextThread()
current = next // Maintain global variable
switchFromTo(outgoing, next)
```

Multiple processors
-------------------

- A modern system can run multiple threads simultaneously in hardware
- We need to maintain information about the `n` running threads on our `n` processors
- When a thread yields on one CPU, we can begin running a new thread there
