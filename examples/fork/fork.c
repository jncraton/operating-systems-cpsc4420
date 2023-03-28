#include <unistd.h>
#include <stdio.h>

int main() {
  int pid = fork();

  printf("PID: %d\n", pid);
}