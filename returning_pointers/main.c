#include <stdio.h>
#include <stdlib.h>

int *form();
int *teste(int num);

int main() {
  printf("atomicbombproject\n");
  int *numero = form();
  printf("%d\n", *numero);
  return 0;
}

int *form() { return teste(255); }
int *teste(int num) {
  int *i = (int *)malloc(sizeof(int));
  *i = num;
  return i;
}
