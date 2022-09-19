#include <bits/stdc++.h>
#define ll long long

ll sumEl(ll array[], ll c_location, ll a_len) {
  ll sum = 0, i = c_location;
  while (i++ < a_len)
    sum += array[i - 1];
  return sum;
}

int main() {
  ll n, i = 0;
  std::cin >> n;
  ll array[n];
  std::iota(array, array + n, 1);

  while (i++ < n)
    std::cout << array[i - 1] << "\n";

  // std::cout << std::__gcd(8, 12) << "\n"; // greatest common divisor
  std::cout << "desde 0 (0-n): " << sumEl(array, 0, n) << "\n";
  std::cout << "a partir de 2 (2-n): " << sumEl(array, 2, n) << "\n";

  // temos o array array com 1,2,3,4,5,6,7
  // encontrando a possibilidade de 2 metades de mesmo valor
  bool isit = !(n * (n + 1) % 4);
  ll each_sum;
  if (!isit) { // caso nao seja, o programa sera finalizado
    std::cout << "NO\n";
    return 0;
  } else {
    std::cout << "YES\n";
    each_sum = (n * (n + 1) / 4);
  }

  // se for
  int k;
  int arr_len;
  // posso fazer maior e menor serem ponteiros mais tarde
  int maior = n - 1;
  int menor = 0;

  // onde serao armazanados os numeros para soma
  int sum_array2[n];
  int sum = 0;
  k = 0;
  int num_count = 0;
  while (each_sum > sum) {
    sum += array[maior--];
    sum_array2[k] = array[maior + 1];
    array[maior + 1] = -1;
    num_count++;
    if (sum < each_sum) {
      sum += array[menor++];
      sum_array2[++k] = array[menor - 1];
      array[menor - 1] = -1;
      num_count++;
    }
    k++;
  }
  sum_array2[k] = -1;

  std::cout << " total da primeira metade da soma ::: " << sum << "\n";
  std::cout << " : " << num_count << ": \n";
  i = 0;
  while (sum_array2[i++] != -1)
    std::cout << sum_array2[i - 1] << "\n";

  std::cout << "segundo array: \n";
  std::cout << " : " << n - num_count << ": \n";
  i = 0;
  while (i++ < n)
    if (array[i - 1] > 0)
      std::cout << array[i - 1] << "\n";

  return 0;
}
