#include <stdio.h>

int main() {
  char *msg = "Hello world";

  printf("Hi\n");
  int len = 0;
  while (1) {
    printf("%p %c %d\n", &msg[1], msg[len], msg[len]);
    len++;
    if (msg[len] == '\0') {
      break;
    }
  }

  printf("Length: %d", len);

  return 0;
}