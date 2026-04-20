# 7.2 POSIX Process Management API

## Process

- Closest to the informal idea of a running program

## Process

- One or more threads
- Virtual memory accessible to those threads
- Other access rights
- Resource allocation context
- Other context (e.g. working directory)

## Process Identification

- Each process has a process ID number (PID)
- All PIDs are positive integers

---

![Process Memory Layout](https://upload.wikimedia.org/wikipedia/commons/thumb/5/50/Program_memory_layout.pdf/page1-960px-Program_memory_layout.pdf.jpg){height=540px}

---

![Process Memory Layout](https://i.sstatic.net/k4hPj.png){height=540px}

## Process Creation

- Processes are created as a `fork` of another
- The only exception is the initial process created by the OS on boot

## Fork

- The `fork` system call can be called from a thread to create a new process
- The parent calling `fork` sees the process ID of the child as a return value
- The child process sees a return value of 0
- The child process is otherwise an exact copy of the parent

---

```c
#include <unistd.h>
#include <stdio.h>

int main() {
  int pid = fork();

  printf("PID: %d\n", pid);
}
```

## Memory

- A process created using fork holds copies of all memory available to the parent process
- This memory is a copy
- Memory is not shared as with threads

## Multiprocessing

- Can be used to improve performance of parallel computations
- Provides different characteristics than threads

## Running new programs

- `exec` can be used to cause a process to begin running a new program

```c
#include <unistd.h>
#include <stdio.h>

int main() {
  execl("/bin/echo", "echo", "Hello, world!", NULL);

  printf("An error has occurred");
}
```

## Fork and Exec

- `fork` creates a copied process
- `exec` can be used to cause only the child to run a new program

---

```c
#include <unistd.h>
#include <stdio.h>

int main() {
  int pid = fork();

  if (!pid) {
    printf("Child launching xterm\n");
    execl("/usr/bin/xterm", "xterm", NULL);
  } else {
    printf("Parent process complete\n");
  }
}
```

## Killing processes

- `kill` can be used to send a signal to a specified process

---

```c
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main() {
  int pid = fork();

  if (!pid) {
    printf("Child launching xterm\n");
    execl("/usr/bin/xterm", "xterm", NULL);
  } else {
    sleep(3);
    printf("Killing %d\n", pid);
    kill(pid, 9);
    printf("Parent process complete\n");
  }
}
```

# Kernel Fork Steps

## Fork

- Requires the kernel to create a nearly identical replica of the calling process
- Involves several mechanical steps to ensure the new process has its own isolated memory and a properly initialized execution state

## Finding a Process Slot

- The kernel must iterate through `ptable` to find an entry where the state is `P_FREE`
- Slot 0 is typically reserved for the kernel and is never used for a new process

## Allocating a Page Table

- The kernel allocates a new page table for the child process using `kalloc_pagetable`
- This new page table must initially include the kernel's identity mappings so that the child can still execute kernel code during system calls and interrupts

## Copying Memory Content

- The kernel iterates through the parent's virtual address space using an iterator like `vmiter`
- For every page that is user-accessible (code, data, stack, and heap):
    1. Allocate a new physical page
    2. Copy the data from the parent's physical page to the child's new physical page
    3. Map this new physical page into the child's page table at the same virtual address used by the parent

## Initializing the Execution State

- The child process must begin execution at the exact same point where the parent called `fork`
- The kernel copies the saved register state from parent to child

## Return Values

- To distinguish the two processes, the kernel modifies the return value register in the child's saved state
  - On x86-64, this means setting `reg_rax` to 0
- The parent's return value is set to the PID of the child

## Marking the Process as Runnable

- The process state is changed from `P_FREE` to `P_RUNNABLE`
- On the next timer interrupt or schedule event, the kernel's scheduler may select the child process to run
