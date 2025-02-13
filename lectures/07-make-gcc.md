Make and GCC
============

Make
----

- Build automation tool
- Performs actions ordered by configured dependencies as defined in makefile

GCC
---

- [GNU Compiler Collection](https://en.wikipedia.org/wiki/GNU_Compiler_Collection)
- Main compiler, linker, and assembler used for this class
- Free and open source optimizing compiler produced by the [GNU project](https://en.wikipedia.org/wiki/GNU_Project)

What is GCC
-----------

- Just a program

```sh
> which gcc
/usr/bin/gcc
```

How to use GCC
--------------

- Run it
- Enter `/usr/bin/gcc` in the shell. If the location of gcc is in your `PATH`, you can simply type `gcc` and the OS will resolve the full path.

```sh
> gcc
gcc: fatal error: no input files
compilation terminated.
```

Compiling Files
---------------


Compile source files into executable

```
> gcc src1.c src2.c --output executable
```

Hello, world
------------

hello.c:

```c
#include <unistd.h>

int main() {
  write(0, "Hello, world!\n", 14);
  return 0;
}
```

Compile
-------

Preprocess, compile, assemble, and link our program to the file `hello`

```sh
> gcc hello.c --output hello
```

Run
---

We now have a new executable file. We can run it in the shell as:

```sh
> ./hello
```

More advance operations
-----------------------

Compile source code into Assembler instructions:

```sh
> gcc -S src.c
```

Compile source code without linking:

```sh
> gcc -c src.c
```
