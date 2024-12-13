#include <math.h>
#include <stdio.h>
#define ENTRY 2

// int calc_pos(int n);

#define calc(n)                                                                \
  (n * n * (n * n - 1) - 32 - (n - 4) * 16 - 16 - (n - 4) * 24 -               \
   (n - 4) * (n - 4) * 8) /                                                    \
      2
int main() {
  printf("%d\n", calc(ENTRY));

  return 0;
}

int calc_pos(int n) {
  return (n * n * (n * n - 1) - 32 - (n - 4) * 16 - 16 - (n - 4) * 24 -
          (n - 4) * (n - 4) * 8) /
         2;
}
