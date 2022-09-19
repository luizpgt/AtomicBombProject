#include <bits/stdc++.h>
#define ll long long

int main() {
  ll num, res;
  int i, count = 0;
  std::cin >> num;

  i = 0;
  res = 1;
  while (i++ < num)
    res *= i;
  for (i = 10; res % i == 0; i *= 10)
    count++;
  std::cout << count << "\n";
  return 0;
}
