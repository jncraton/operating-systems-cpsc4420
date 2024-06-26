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
