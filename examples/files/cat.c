#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char ** argv) {
  if (argc != 2) exit(1);

  char buf[1024];
  int file = open(argv[1], O_RDONLY);

  int bytes_read;

  while (bytes_read = read(file, buf, 1024)) {
    write(1, buf, bytes_read);
  }

  close(file);
}
