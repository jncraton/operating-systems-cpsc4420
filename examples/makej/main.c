#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int divide(int a, int b);

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    fprintf(stderr, "usage: %s <op> <a> <b>\n", argv[0]);
    return 1;
  }
  char *op = argv[1];
  int a = atoi(argv[2]);
  int b = atoi(argv[3]);
  int r;
  if (strcmp(op, "+") == 0 || strcmp(op, "add") == 0)
  {
    r = add(a, b);
  }
  else if (strcmp(op, "-") == 0 || strcmp(op, "sub") == 0)
  {
    r = sub(a, b);
  }
  else if (strcmp(op, "*") == 0 || strcmp(op, "mul") == 0)
  {
    r = mul(a, b);
  }
  else if (strcmp(op, "/") == 0 || strcmp(op, "div") == 0)
  {
    r = divide(a, b);
  }
  else
  {
    fprintf(stderr, "unknown op: %s\n", op);
    return 1;
  }
  printf("%d\n", r);
  return 0;
}
