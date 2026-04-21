#include <stdio.h>
#include <stdlib.h>

int main() {
  int n = 5;
  int *arr = malloc(n * sizeof(int));

  if (arr == NULL) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    arr[i] = i * 10;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }

  free(arr);

  // Fails, not enough memory
  arr = malloc(0xffffffffff);

  printf("%p", arr);

  return 0;
}
