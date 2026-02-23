#include <stdio.h>
#include <stdlib.h>

int divide(int a, int b)
{
  if (b == 0)
  {
    fprintf(stderr, "division by zero\n");
    exit(1);
  }
  return a / b;
}
