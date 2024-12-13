#include <iostream>

int main() {
  long long n, total = 0;
  std::cin >> n;
  while (n >= 5) {
    n /= 5;
    total += n;
  }
  std::cout << total << "\n";

  return 0;
}
