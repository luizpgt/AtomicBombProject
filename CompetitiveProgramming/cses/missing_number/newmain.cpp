#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
  // it saved me time from 0.07s to 0.03
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, x, i = 0;
  cin >> n;
  ll ar[n];
  for (i = 0; i < n - 1; i++) {
    cin >> x;
    ar[x - 1] = x;
  }

  for (i = 0; i < n; i++) {
    if (ar[i] != i + 1) {
      cout << i + 1;
      break;
    }
  }
  return 0;
}
