3.1 - 3.2 Thread States
=======================

Threads
-------

- A sequence of computational instructions run one after another
- Requires OS-level management for runtime data

Thread Switching
----------------

- A thread can ask the OS to run another thread by calling `yield()`
- The OS may take control of the CPU using pre-emptive multitasking

How does the OS determine which thread to switch to?

Scheduling
----------

- OS determines which process to run next
- Decision should be based on what the users of the system needs
- Should optimize resource use

Waiting Threads
---------------

- Threads may be blocked waiting for I/O
- e.g. a webserver waiting on a disk access

Busy Waiting
------------

- Loop until the task is complete, checking frequently
- Wastes CPU time that could be used by other threads
- OS should implement a better mechanism

Queues
------

- Run queue - Queue of threads that can be run now
- Wait queue - Queue of threads waiting on something
    - 1 queue per wait reason