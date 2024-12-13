#include <bits/stdc++.h>
typedef long long ll;

int main() {
  ll nt, rPile, lPile, i, maior, menor;
  std::cin >> nt;
  ll array[nt * 2];

  i = 0;
  while (i++ < nt * 2) {
    std::cin >> rPile >> lPile;
    array[i - 1] = rPile;
    array[i++] = lPile;
  }

  i = 0;
  ll util;
  while (i++ < nt * 2) {
    maior = array[i - 1];
    menor = array[i++];
    if (menor > maior) {
      util = menor;
      menor = maior;
      maior = util;
    }

    // pode ser feito somente a verificacao com modulo de 3 e menor*2 >= maior
    if (((menor + maior) % 3 == 0) &&
        (menor * 2 >= maior || menor == maior || menor == maior - 1))
      std::cout << "YES"
                << "\n";
    else
      std::cout << "NO"
                << "\n";
  }

  return 0;
}
