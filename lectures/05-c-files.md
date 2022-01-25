Files in C
==========

What is a file?
---------------

- Resource for storing data
- Typically stored on persistent media (HDD, SSD, etc)
- Group together and organized as a file system

Organization
------------

- Linux organization described in [FHS](https://en.wikipedia.org/wiki/Filesystem_Hierarchy_Standard)
- Tree structure descending from root node `/`

Virtual File Systems
--------------------

- Used to read and write data from the kernel
- `/dev`, `/sys`, `/proc`, `/run`
- e.g. `cat /proc/loadavg`

Using files
-----------

- Kernel provides [system calls](https://github.com/torvalds/linux/blob/master/arch/x86/entry/syscalls/syscall_64.tbl) (`open`, `read`, `write`, `close`)
- System call headers are available in the [kernel source](https://github.com/torvalds/linux/blob/master/include/linux/syscalls.h)
- Files are accessed as streams of bytes
- Bytes are read and written starting from the beginning of the file by default

File API
--------

1. `open` file to get a file descriptor for the open file
2. `read` or `write` using the file descriptor
3. `close` to tell the kernel we are done with the file

---

Basic file reading
------------------

```c
#include <unistd.h>
#include <fcntl.h>

void main() {
  char buf[2048];
  int file = open("/proc/loadavg", O_RDONLY);

  int len = read(file, buf, 2048);
  write(1, buf, len);

  close(file);
}
```

cat implementation
------------------

```c
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char ** argv) {
  if (argc != 2) exit(1);

  char buf[1024];
  int file = open(argv[1], O_RDONLY);

  int bytes_read;

  while (bytes_read = read(file, buf, 1024)) {
    write(1, buf, bytes_read);
  }

  close(file);
}
```

File permissions
----------------

- On Unix systems, files can be set as readable, writeable, and executable
- These can be defined for the file owner, file owner group, and everyone

Permission encoding
-------------------

- 3 bits
    - Read (4)
    - Write (2)
    - Execute (1)
- 3 numbers used to store user, group, and world respectively

Example
-------

- User read and write, group read, world read:
    - 644
- User read, write, exec, group read and exec, world nothing
    - 750

Modifying Permissions
---------------------

- `chmod` - change file mode bits

```
chmod 775 myfile.c
```

- `chown` - change file owner and group

```
chown user:group myfile.c
```

- `chgrp` - change group ownership

```
chgrp group myfile.c
```

cp implementation
-----------------

```c
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char ** argv) {
  if (argc != 3) exit(1);
  
  int in = open(argv[1], O_RDONLY);
  int out = open(argv[2], O_WRONLY|O_CREAT, 0644);

  char buf[1024];
  int bytes_read;

  while (bytes_read = read(in, buf, 1024)) {
    write(out, buf, bytes_read);
  }

  close(in);
  close(out);
}
```
