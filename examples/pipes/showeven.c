#include <stdio.h>

int main(void) {
  int value;

  while (scanf("%d", &value) != EOF) {
    if (value % 2 == 0) {
      printf("showeven found even value: %d\n", value);
      fflush(stdout);
    }
  }

  return 0;
}
