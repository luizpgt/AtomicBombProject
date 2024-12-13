#include <bits/stdc++.h>
#include <cmath>

using namespace std;

#define inv(num) (num) ? (num = 0) : (num = 1)

int main() {
  int n;
  scanf("%d", &n);
  int lns = pow(2, n);
  int i;
  i = 0;
  int ar[n];

  while (i < n) {
    ar[i++] = 0;
  }

  int k;
  for (k = 0; k < lns; k++) {
  }

  i = 0;
  while (i < n)
    printf("%d", ar[i++]);

  return 0;
}
