7.3 Protecting Memory
=====================

Virtual Memory
--------------

- Provides the framework for memory protection
- Different mapping can be used for different processes
- Mappings can include memory permission bits

Processor Modes
---------------

- Code running as part of a user application may only access its own memory (user mode)
- Code running as part of the OS needs access to everything (kernel mode)

Kernel Mode
-----------

- All instructions are available
  - I/O
  - Change modes
  - Change memory permissions

User Mode
---------

- Normal instructions are usable
- Priviledged instructions will fail
- Illegal instructions are caught by the OS (trap)

System Calls
------------

- Effectively illegal operations
- OS traps the call and performs some requested operation
- Control typically returns to the process that requested the system call

Threads
-------

- Can be implemented differently based on protection level and mode switch
- Kernel thread - run and scheduled in kernel mode
- Native thread (or just thread) - run in user mode, scheduled in kernel mode
- User thread - run and scheduled in user mode

Multiple Address Spaces
-----------------------

- Each process has its own virtual address space
- Used by OS X, Windows, Linux, etc
- Memory mappings are used to control permissions and access

7.4 Representing Access Rights
==============================

Protection system
-----------------

- Controls access to objects by subjects
- Object is what is being protected
- Subject is trying to access the object

Operations
----------

- Associated with an object
- Can be performed by a subject

Access Right
------------

- Permission for a subject to perform an operation on an object

Principal
---------

- Rights are attached to subjects
- A *principal* is often used to determine appropriate rights
- Processes may be the subject, but their rights reflect those of the user that owns them

Capabilities
------------

- Indirect reference to object
- Includes information needed to locate object and a set of access rights
- Also known as handles (Windows) and descriptors (POSIX)