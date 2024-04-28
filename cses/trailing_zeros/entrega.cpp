#include <bits/stdc++.h>

int main() {

  long long num, res = 1, fin = 0;
  std::cin >> num;

  while (res <= num) {
    res *= 5;
    fin += num / res;
  }

  std::cout << fin << "\n";
  return 0;
}
