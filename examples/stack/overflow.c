#include <stdio.h>

int count = 0;

void recurse() {
  printf("%d\n", count);
  count++;

  recurse();
}

int main() {
  recurse();
}
