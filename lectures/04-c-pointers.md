Pointers
========

Pointers
--------

- Provide references to memory
- Just an unsigned integer of the appropriate size
- `int *a` defines pointer `a`
- `*b` dereferences `b`
- `&c` returns the address of `c` 

--- 

```c
#include <stdio.h>

int main() {
  int a = 5;
  int * b = &a;

  printf("%x", b);
}
```

Displaying the address of a value

---

#include <stdio.h>

int main() {
  int a = 5;
  int * b = &a;

  *b += 1;

  printf("%d", *b);
}

Dereferening a pointer

---

```c
#include <stdio.h>

int increment(int* value) {
  *value += 1;
}

int main() {
  int a = 1;
  increment(&a);

  printf("%d", a);
}
```

Passing pointers
