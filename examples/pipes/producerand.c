#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(void) {
  while (1) {
    int random_val = rand();
    int delay = (rand() % 3) + 1;

    printf("%d\n", random_val);
    fprintf(stderr, "producerand generated %d\n", random_val);
    fflush(stdout);

    sleep(delay);
  }

  return 0;
}
