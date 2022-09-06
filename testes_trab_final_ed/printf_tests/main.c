#include <stdio.h>

#define decimalUse(val) ((vol - ((int *)vol)) == 0 ? 0 : 1))
#define isLitre(vol) ((vol >= 1000) ? (1) : (0))
#define str(vol) (isLitre(vol) == 1 ? (decimalUse(vol) == 0 ? ("%.0lf L", vol/1000) : ("%.2lf L", vol/1000)) : ("%2.lf Ml", vol))
#define strid ("somente um teste %d", 5)
int main() {
  double x;
  char *str = "%.2lf{x}";
  printf(strid)
  return 0;
  while (1) {
    scanf("%lf", &x);
    //printf("%s", str(x));
  }
  return 0;
}
