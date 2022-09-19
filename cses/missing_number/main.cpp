#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  ll n, i = -1, x, k;
  cin >> n;
  n--;
  ll ar[n];
  while (++i < n) {
    cin >> ar[i];
    k = i;
    while (k > 0 and ar[k] < ar[k - 1]) {
      x = ar[k];
      ar[k] = ar[k - 1];
      ar[k-- - 1] = x;
    }
  }
  for (i = 1; i == ar[i - 1]; i++)
    ;
  cout << i;

  return 0;
}
