#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void* child(void *ignored) {
  sleep(1);
  printf("Child is done sleeping for 1 second.\n");
  return NULL;
}

int main() {
  pthread_t child_thread;
  
  int error;
  error = pthread_create(&child_thread, NULL, child, NULL);
  if (error) {
    fprintf(stderr, "pthread_create failed with error %d\n", error);
  }

  sleep(3);
  printf("Parent is done sleeping for 3 seconds.\n");
  return 0;
}
