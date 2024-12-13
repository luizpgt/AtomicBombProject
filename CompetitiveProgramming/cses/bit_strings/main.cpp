#include <bits/stdc++.h>
#define ll long long
#define M 1000000007

ll up2(ll n) {
  ll i, res;
  i = 0, res = 1;
  while (i++ < n) {
    res = (res << 1) % M;
  }
  return res;
}

int main() {
  long long n, res_n, i;
  std::cin >> n;
  res_n = 1, i = 0;
  while (i < n) {
    // res_n += pow(2, i++);
    res_n = res_n % M;
    res_n = (res_n + up2(i++)) % M;
  }
  std::cout << res_n << "\n";
  return 0;
}
