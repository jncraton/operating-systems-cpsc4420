#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ACCOUNTS 16
#define THREADS 16

pthread_mutex_t locks[ACCOUNTS];

void* transfer(void* arg) {
  long id = (long)arg;
  
  while (1) {
    int from = rand() % ACCOUNTS;
    int to = rand() % ACCOUNTS;

    if (from == to) {
      continue;
    }

    pthread_mutex_lock(&locks[from]);
    pthread_mutex_lock(&locks[to]);

    printf("Thread %ld transferred from %d to %d\n", id, from, to);

    pthread_mutex_unlock(&locks[to]);
    pthread_mutex_unlock(&locks[from]);
  }
  return NULL;
}

int main() {
  pthread_t threads[THREADS];

  for (int i = 0; i < ACCOUNTS; i++) {
    pthread_mutex_init(&locks[i], NULL);
  }

  for (long i = 0; i < THREADS; i++) {
    pthread_create(&threads[i], NULL, transfer, (void*)i);
  }

  for (int i = 0; i < THREADS; i++) {
    pthread_join(threads[i], NULL);
  }

  return 0;
}