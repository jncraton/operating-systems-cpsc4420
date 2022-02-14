#include <pthread.h>
#include <stdio.h>

#define THREADS 16

int tickets_remaining = 100000;

pthread_mutex_t sale_mutex;


long int child(long int thread_num) {
  long tickets_sold = 0;

  while (tickets_remaining > 0) {
    pthread_mutex_lock(&sale_mutex);
    if(tickets_remaining > 0) {
      tickets_remaining--;
      tickets_sold++;
    }
    pthread_mutex_unlock(&sale_mutex);
  }

  printf("Thread %ld sold %ld tickets.\n", thread_num, tickets_sold);

  return tickets_sold;
}

int main() {
  pthread_t child_thread[THREADS];

  pthread_mutex_init(&sale_mutex, 0);

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

  pthread_mutex_destroy(&sale_mutex);

  printf("A total of %ld tickets were sold\n", sum);
  return 0;
}