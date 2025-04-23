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

8.4 Disk Space Allocation
=========================

Virtual Memory
--------------

- Maps virtual address space to physical memory (typically DRAM)
- Storage is not persistent
- Mapping happens in chunks called pages

File System
-----------

- Maps positions in files to persistent storage (typically disks)
- Storage is persistent
- Mapping happens in chunks called blocks

Allocations
-----------

- Any block in a file could be mapped to any block on a disk
- Not all choices are equal
- Goal is to optimize space and time usage

Wasted Space
------------

- Blocks are fixed sizes
- Using less than a full block of space creates unused space that can never be used

Internal Fragmentation
----------------------

- Unusable space that is allocated, but not available for use
- Occurs in the empty space at the end of blocks

External Fragmentation
----------------------

- Unusable space that is not allocated, but too small to be useful
- Occurs in the relatively small gaps between allocated blocks

Extents
-------

- Contiguous chunks of files

Locality Guidelines
-------------------

- Files should be broken into as few extents as possible
- If multiple extents are required, they should be as close as possible
- Files that are used together should be stored together

Locality Policies
-----------------

- Assume files in a directory are used together and store them together
- Measure usage and assume that files that were accessed together with be accessed together in the future

Tracking Allocations
--------------------

- Many implementations
- ext3 stores a bit representing free or used for each block group
- Each block group contains a similar mapping for its blocks

Allocation Policies
-------------------

- Files in a directory will often be stored in a block group to improve locality
- Subdirectories are often stored in new block groups

Delayed Allocation
------------------

- File size is not generally known at creation time
- Writes to files a buffered to RAM before being written to disk
- The OS may choose to buffer many writes in order to determine appropriate file size before performing allocation
