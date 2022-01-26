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

New Instruction
---------------

- switchFromTo(currentThread, newThread)
- Instructs the CPU to move its execution from one thread to another

---

Thread A            Thread B
------------------- ---------
A1
A2
switchFromTo(A, B)
                    B1
                    B2
                    switchFromTo(B, A)
A4
A5

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
- The stack pushed to hold thread state when switching just like when calling a function

Psuedocode
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
