Fork
======

---

```c
#include <unistd.h>
#include <stdio.h>

int main() {
  int i;
  i = fork();

  printf("%d\n", i);
}
```

Process
-------

- Closest to the informal idea of a running program

Process
-------

- One or more threads
- Virtual memory accessible to those threads
- Other access rights
- Resource allocation context
- Other context (e.g. working directory)

Process Identification
----------------------

- Each process has a process ID number (PID)
- All PIDs are positive integers

Process Creation
----------------

- Processes are created as a `fork` of another
- The only exception is the initial process created by the OS on boot

Fork
----

- The `fork` system call can be called from a thread to create a new process
- The parent calling `fork` sees the process ID of the child as a return value
- The child process sees a return value of 0
- The child process is otherwise an exact copy of the parent

Memory
------

- A forked process sees a copy of its parent's memory
- Clobbering the other processes memory is not possible
- Communication via memory modification is not available
