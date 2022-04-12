8.6 Directories and Indexing
============================

Files
-----

- Provide access to blobs of data
- Include names for easy access
- Stored in a hierarchy

Directories
-----------

- Provide hierarchical levels for storing files
- Each name in a director points to one file
- Names within a directory are unique

Unordered Linear List
---------------------

- Simple
- Trivial O(1) modification
- O(n) lookup where n is number of files in directories
- Large number of files create inefficiency

Hash Tables
-----------

- O(1) lookup without collisions
- Does not provide a way to iterate name in order

![Hash Table](https://upload.wikimedia.org/wikipedia/commons/7/7d/Hash_table_3_1_1_0_1_0_0_SP.svg)

B+-Tree
-------

- Tree with large fan out to reduce number of lookups
- O(log n) search
- Internal nodes contain pointers to leaves and no values
- Nodes include links to next sibling to form a linked list

![B+-Tree](https://upload.wikimedia.org/wikipedia/commons/3/37/Bplustree.png)

B+-Tree
-------

- Commonly used for directory storage
- Used by NTFS (Microsoft), HFS (Apple), and XFS (open source)

8.7 Metadata Integrity
======================

Buffering Writes
----------------

- Data to be written to disk is stored temporarily in RAM
- RAM loses state without power
- What happens to buffered writes when the system is power cycled?

Data Loss
---------

- Buffered data will be lost
- Application programs need to be able to handle this
- Databases may solve this using a write-ahead log

Metadata Consistency
--------------------

- Metadata must not become inconsistent
- Blocks that are in use must be marked as not available to others
- Blocks marked as in use should be pointed to by an inode

Irreparable Corruption
----------------------

- Must be avoided
- Example is two files sharing an underlying data block

Noncritical Reparable Corruption
--------------------------------

- Can be fixed after the fact
- Lost block in a single file

Critical Reparable Corruption
-----------------------------

- Can be fixed after the fact
- Must be fixed before the system resumes it regular work
- Example is a block in use by a file but not marked as in-use

Consistency Strategies
----------------------

- Single-block updates
  - Journaling
  - Shadow Paging
- Careful ordering


Journaling
----------

- Each logical change is only a single block written to persistent storage
- This single block is the commit record for a transaction
- Partially complete transactions can be rolled back

Shadow Paging
-------------

- Creates new data structures instead of modifying existing structures
- Single block change update pointer to current metadata structure