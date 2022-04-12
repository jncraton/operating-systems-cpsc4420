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

- Tree with large fanout to reduce number of lookups
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
