#include <unistd.h>
#include <stdio.h>

int main() {
  int pid = fork();

  if (!pid) {
    printf("Child launching xterm\n");
    execl("/usr/bin/xterm", "xterm", NULL);
  } else {
    printf("Parent process complete\n");
  }
}