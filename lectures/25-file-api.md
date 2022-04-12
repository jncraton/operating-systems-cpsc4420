8.1 Files and Other Persistent Storage
======================================

Persistence
-----------

- Data stored in memory disappears on power failure or reboot
- The OS should provide a way to store data longer term

Access
------

- Provide a means to reference stored objects by name
- Objects could also be accessed by contents

Files
-----

- Blend persistence and access

Common forms of persistent storage
----------------------------------

- File - Array of bytes
- Table - Array of typed data fields
- Persistent Object - Serialized data structure from a programming context

Common access services
----------------------

- Hierarchical directories mapping names to objects
- Indexes providing access based on contents

8.2 Storage Technology
----------------------

- The recent history of persistent storage has been dominated by spinning hard drives
- Solid-state drives have begun to replace spinning drives

Disk Drive
----------

- Store data in 512 byte blobs called sectors (other sizes are possible)
- Conceptually, an array of sectors
- The processor can request that an ordered group of sectors be transferred to RAM or vice versa

---

![Disk drive hardware](https://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/Laptop-hard-drive-exposed.jpg/627px-Laptop-hard-drive-exposed.jpg)

Disk drive performance
----------------------

- Linear reads are much faster than random reads
- Head seeking takes
- Rotational latency (waiting for the sector to arrive under the head) also adds to latency
- Reads should be queued on the drive to allow the drive to make correct performance decisions

SSDs
----

- Do not experience mechanical seeks or rotational latency
- Less penalty for random reads
- Generally lower latency and high bandwidth than spinning drives
- Currently more expensive per byte

8.3 POSIX File API
==================

Standardization
---------------

- UNIX-like systems share the same standards (POSIX)
- POSIX is implemented by Unix systems, Mac OS, and Linux

Referencing files
-----------------

- Files are commonly referenced by path name
- Files are also referenced by an integer called a file descriptor

File descriptor
---------------

- Integer
- References a files
- Can be obtained using `open` system call

Other endpoints
---------------

- Descriptors are often used with persistent files
- They may also be used with other destination for input and output
- Examples include `stdout`, sockets, and hardware devices

Inherited descriptors
---------------------

- All processes inherit at least 3 file descriptors
    - Standard input (0)
    - Standard output (1)
    - Standard error (2)

unistd.h
--------

- Includes definitions for many POSIX API components

Redirection
-----------

- Standard input and output are generally the terminal
- They can be redirected elsewhere via the shell

Open
----

- Get a new file descriptor
- Requires filename and a mode to open a file

Modes
-----

- O_WRONLY - Write only
- O_RDONLY - Read only
- O_RDWR - Read and write
- O_CREAT - Create file if not present
- O_TRUNC - Empty file before writing

Close
-----

- Closes a file descriptor allowing the OS to free its memory
- All open descriptors are closed on program termination

Memory Mapped I/O
-----------------

- Map a file to a processes virtual address space
- Loads and stores to memory provide random read and write access to the file

Issues with `mmap`
------------------

- No easy control over when updates become persistent
- There can be no write only permissions
- Implies that files size is known

Copying
-------

- `read` and `write` can be used to copy file sections to memory
- `pread` and `pwrite` work similarly, but require a position

Sequential operation
--------------------

- Some descriptions (e.g. network sockets) only allow sequential operation
- `read` and `write` can be used to copy data sequentially

Implicit position
-----------------

- `read` and `write` update a stored position in a file
- `lseek` can be used to adjust this stored position
