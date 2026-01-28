#include <unistd.h>
#include <fcntl.h>

void main() {
  char buf[2048];
  int file = open("/proc/loadavg", O_RDONLY);
  
  int len = read(file, buf, 2048);
  write(1, buf, len);

  close(file);
}