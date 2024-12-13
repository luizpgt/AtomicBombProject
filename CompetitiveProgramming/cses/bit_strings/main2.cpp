#include <bits/stdc++.h>
#define M 1000000007
int main() {
  long long n, i = 0, res = 1;
  std::cin >> n;
  while (i++ < n)
    res = (res << 1) % M;
  std::cout << res << "\n";
  return 0;
}
