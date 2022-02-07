#include <pthread.h>
#include <stdio.h>

#define THREADS 16

int tickets_remaining = 100000;

long int child(long int thread_num) {
  long tickets_sold = 0;

  while (tickets_remaining > 0) {
    tickets_remaining--;
    tickets_sold++;
  }

  printf("Thread %ld sold %ld tickets.\n", thread_num, tickets_sold);

  return tickets_sold;
}

int main() {
  pthread_t child_thread[THREADS];

  for (unsigned long i = 0; i < THREADS; i++) {
    int code;
    code = pthread_create(&child_thread[i], NULL, (void*)child, (void*)i);
    if (code) {
      fprintf(stderr, "pthread_create failed with code %d\n", code);
    }
  } 

  unsigned long child_sum;
  unsigned long sum = 0;

  for (unsigned int i = 0; i < THREADS; i++) {
    pthread_join(child_thread[i], (void*)&child_sum);
    sum += child_sum;
  }

  printf("A total of %ld tickets were sold\n", sum);
  return 0;
}