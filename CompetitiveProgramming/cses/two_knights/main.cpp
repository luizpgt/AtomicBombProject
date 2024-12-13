#include <bits/stdc++.h>
#define ll long long

#define calc(n)                                                                \
  (n * n * (n * n - 1) - 32 - (n - 4) * 16 - 16 - (n - 4) * 24 -               \
   (n - 4) * (n - 4) * 8) /                                                    \
      2

int main() {
  ll n, i = 0;
  std::cin >> n;
  while (i++ < n)
    std::cout << calc(i) << "\n";
  return 0;
}
