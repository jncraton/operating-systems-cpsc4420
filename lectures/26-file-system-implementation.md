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
- Goal is to opimize space and time usage

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

8.5 Metadata
============

Metadata
--------

- Data about data
- Information about where block of a file are stored
- File access control
- Dates and times

File Names
----------

- Not really metadata
- Names provide a reference to a file
- Names are not a property of a file
- Multiple names can point to the same file

Data Location Metadata
----------------------

- ext3 stores file metadata in blocks called inodes
- Each inode stores file metadata including data locations
- inodes are stored in a linear array
- Each file has a unique inode

---

![inode metadata](media/8-6.png)

Example
-------

`ls -i` will list inode numbers

Indirect Blocks
---------------

- We want inodes to be a fixed, relatively small size
- Some files will need more metadata
- inodes are able to link to additional blocks for more metadata

---

![inode metadata overflowing to indirect block](media/8-7.png)

Double and Triple Indirection
-----------------------------

- Some files are very large
- We create a deeper tree
- The early blocks are still linked direction from the inode then the single indirect block

---

![Double indirect storage](media/8-9.png)

---

![Tree](media/8-10.png)
