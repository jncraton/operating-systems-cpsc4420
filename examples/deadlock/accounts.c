#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ACCOUNTS 16
#define THREADS 16
#define INITIAL_BALANCE 100

int balances[ACCOUNTS];
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

    if (balances[from] > 0) {
      balances[from]--;
      balances[to]++;

      int sum = 0;

      for (int i = 0; i < ACCOUNTS; i++) {
        sum += balances[i];
      }
      printf("Thread %2ld: %2d -> %2d | Balances: Account %2d: $%3d, Account %2d: $%3d Total Balance: $%4d\n",
             id, from, to, from, balances[from], to, balances[to], sum);
    }

    pthread_mutex_unlock(&locks[to]);
    pthread_mutex_unlock(&locks[from]);
  }
  return NULL;
}

int main() {
  pthread_t threads[THREADS];

  for (int i = 0; i < ACCOUNTS; i++) {
    balances[i] = INITIAL_BALANCE;
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