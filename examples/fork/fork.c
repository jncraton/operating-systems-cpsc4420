#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int pid = fork();

  printf("PID: %d\n", pid);
}