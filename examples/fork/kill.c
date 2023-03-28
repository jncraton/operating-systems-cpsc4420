#include <unistd.h>
#include <stdio.h>
#include <signal.h>

int main() {
  int pid = fork();

  if (!pid) {
    printf("Child launching xterm\n");
    execl("/usr/bin/xterm", "xterm", NULL);
  } else {
    sleep(3);
    printf("Killing %d\n", pid);
    kill(pid, 9);
    printf("Parent process complete\n");
  }
}