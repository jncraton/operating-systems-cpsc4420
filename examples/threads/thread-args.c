#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define SUM_TO 10

void* square(void * num) {
  long num_int = *(long*)num;

  printf("Child thread computing square of %d\n", num_int);

  return (void*)(num_int * num_int);
}

int main() {
  pthread_t child_thread[SUM_TO+1];
  long inputs[SUM_TO+1];
  
  int error;
  for (int i = 1; i<=SUM_TO; i++) {
    inputs[i] = i;
    error = pthread_create(&child_thread[i], NULL, square, &inputs[i]);
    if (error) {
      fprintf(stderr, "pthread_create failed with error %d\n", error);
    }
  }

  long long sum = 0;
  long squares[SUM_TO+1];

  for (int i = 1; i<=SUM_TO; i++) {
    pthread_join(child_thread[i], (void*)&squares[i]);
    sum += squares[i];
  }

  printf("Sum of squares from 1 to %d is %ld.\n", SUM_TO, sum);
  
  return 0;
}
