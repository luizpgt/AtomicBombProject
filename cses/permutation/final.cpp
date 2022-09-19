#include <bits/stdc++.h>

int main() {
  int n, i = 0, k = 0;
  scanf("%d", &n); // mais rapido que cin >> n;
  int ar[n];
  int res[n];
  std::iota(ar, ar + n, 1);

  if (n <= 4) {
    if (n == 4)
      printf("2 4 1 3");
    else if (n == 1)
      printf("1");
    else
      printf("NO SOLUTION\n");
    return 0;
  }

  i = k = 0;
  while (k < n) {
    if (i >= n)
      i = 1;
    res[k++] = ar[i];
    i += 2;
  }

  for (i = 0; i < n; i++)
    printf("%d ", res[i]);

  return 0;
}
