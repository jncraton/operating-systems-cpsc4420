#include <unistd.h>
#include <stdio.h>

int main() {
  execl("/bin/echo", "echo", "Hello, world!", NULL);

  printf("An error has occurred");
}