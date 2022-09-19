#include <bits/stdc++.h>

int main() {
  int n;
  scanf("%d", &n); // mais rapido que cin >> n;
  int ar[n];
  std::iota(ar, ar + n, 1);
  int i = 0;
  for (i = 0; i < n; i++)
    printf("%d ", ar[i]);
  printf("\n");

  int aux;

  int it = n % 2 ? std::floor(n / 2) : std::floor(n / 2) - 1;

  if (n <= 4) {
    if (n == 4)
      printf("2 4 1 3");
    else if (n == 1)
      printf("1");
    else
      printf("NO SOLUTION\n");
    return 0;
  }
  int res[n];
  i = 0;
  int k = 0;
  while (k < n) {
    if (i >= n)
      i = 1;
    res[k++] = ar[i];
    i += 2;
  }

  /*
  while (i < it) {
    aux = ar[k];
    ar[k] = ar[k + (i + 1)];
    ar[k + (i + 1)] = aux;
    k++;
    i++;
    if (i == it && n % 2 == 0) {
      aux = ar[it + 1];
      ar[it + 1] = ar[n - 1];
      ar[n - 1] = aux;
    }
  }
  */

  for (i = 0; i < n; i++)
    printf("%d ", res[i]);
  printf("\n");

  return 0;
}
