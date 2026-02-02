#include <unistd.h>

int main() {
  int i = write(1, "Hello, world!\n", 14);
  return i;
}
