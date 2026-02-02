#include <stdio.h>

typedef struct {
  int x;
  int y;
  int z;
} Vec;

int main() {
  int nums[3];
  nums[1] = 5;

  Vec v;
  v.x = 384;
  v.y = 42;

  Vec *p = (Vec*)nums;

  printf("%d\n", *((int*)(&v)+4)); // v.y
}
