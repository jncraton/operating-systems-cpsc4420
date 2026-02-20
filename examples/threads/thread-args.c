#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define SUM_TO 10

void *square(void *num_ptr) {
  long num = *(long *)num_ptr;

  printf("Child thread computing square of %ld\n", num);

  return (void *)(num * num);
}

int main() {
  pthread_t child_thread[SUM_TO];
  long inputs[SUM_TO];

  int error;
  for (int i = 0; i < SUM_TO; i++) {
    inputs[i] = i + 1;
    error = pthread_create(&child_thread[i], NULL, square, &inputs[i]);
    if (error) {
      fprintf(stderr, "pthread_create failed with error %d\n", error);
    }
  }

  long long sum = 0;
  long squares[SUM_TO];

  for (int i = 0; i < SUM_TO; i++) {
    pthread_join(child_thread[i], (void *)&squares[i]);
    sum += squares[i];
  }

  printf("Sum of squares from 1 to %d is %lld.\n", SUM_TO, sum);

  return 0;
}
