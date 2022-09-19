#include <bits/stdc++.h>
#define ll long long

int main() {
  ll n, i, k, maior, menor, sum, num_count;
  std::cin >> n;
  ll array[n];
  std::iota(array, array + n, 1);
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
  // posso fazer maior e menor serem ponteiros mais tarde
  maior = n - 1;
  menor = 0;

  // onde serao armazanados os numeros para soma
  ll sum_arr[n];
  sum = 0;
  k = 0;
  num_count = 0;
  while (each_sum > sum) {
    sum += array[maior--];
    sum_arr[k] = array[maior + 1];
    array[maior + 1] = -1;
    num_count++;
    if (sum < each_sum) {
      sum += array[menor++];
      sum_arr[++k] = array[menor - 1];
      array[menor - 1] = -1;
      num_count++;
    }
    k++;
  }
  sum_arr[k] = -1;
  std::cout << num_count << "\n";
  i = 0;
  while (sum_arr[i++] != -1)
    std::cout << sum_arr[i - 1] << " ";
  std::cout << "\n";

  std::cout << n - num_count << "\n";
  i = 0;
  while (i++ < n)
    if (array[i - 1] > 0)
      std::cout << array[i - 1] << " ";
  std::cout << "\n";
  return 0;
}
