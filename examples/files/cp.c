#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char ** argv) {
  if (argc != 3) exit(1);
  
  int in = open(argv[1], O_RDONLY);
  int out = open(argv[2], O_WRONLY|O_CREAT, 0644);

  char buf[1024];
  int bytes_read;

  while (bytes_read = read(in, buf, 1024)) {
    write(out, buf, bytes_read);
  }

  close(in);
  close(out);
}