C Types
=======

Common types
------------

- `int`, `char`, `float`
- `unsigned int`, `long int`
- Pointers - `int*`, `char*`

Other Types
-----------

- Arrays - `[1, 2, 3]` (essentially just pointers)
- `struct`
- `enum`

Batteries not Included
----------------------

- Most "complex" features are delegated to libraries
- The core language doesn't support common types such as strings
- The standard library (written in C) is part of the standard and many implementations are available

Standard Library
----------------

- [libc](https://en.wikipedia.org/wiki/C_standard_library)
- Many implementations available (BSD libc, glibc, MSVCRT.DLL, etc)
- Defines interfaces for strings, math, I/O, OS operations, and more

Hello World
-----------

```c
#include <stdio.h>

int main() {
  printf("Hello, world!\n");
}
```

unistd.h
--------

- Not part of the C standard library
- Provides access to POSIX operating system API
- [More info](https://en.wikipedia.org/wiki/Unistd.h)

Hello World
-----------

```c
#include <unistd.h>

int main() {
  write(1, "Hello, world!\n", 14);
}
```

Format Strings
--------------

- Allow values of various types to be interpolated into strings
- Used by `printf`, `fprintf`, `scanf`, and others

---

```c
#include <stdio.h>

int main() {
  int a = 1;
  char b = 'a';
  float c = 2.0;

  printf("%d %c %f\n", a, b, c);
}
```

Functions
---------

```c
#include <stdio.h>

int add(int a, int b) {
  return a + b;
}

int main() {
  printf("%d", add(1,2));
}
```
