#include <stdio.h>
#include <stdlib.h>

int main() {

  int *pointer = malloc(sizeof(int));
  int i = 0;
  *pointer = 5;
  printf("new value of i-> %d\n", i);
  printf("value of pointer -> %d\n", *pointer);
  free(pointer);
  return 0;
}
