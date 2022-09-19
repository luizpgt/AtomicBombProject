#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 1e6;

int main() {
  char string[MAX];
  std::cin >> string;
  int str_len;
  for (str_len = 0; string[str_len]; str_len++)
    ;
  std::cout << "size of string " << str_len << "\n";
  char palindrome[str_len];
  int begin = 0, end = str_len - 1;
  int odd_letters = 0;
  int even_letter = 0;

  int i, j;
  char *exists = NULL;
  char aux, cor;
  while (string[i]) {
    aux = string[i];
    i++;
  }
  // encontrar a quantia de cada letra que se encontra na string
  char let_list[str_len];
  int let_qtd[str_len];

  j = 0;
  int k = 0;
  for (i = 0; string[i]; i++) {
    aux = string[i];
    while (let_list[k++])
      if (aux == palindrome[k])
        continue;
    let_list[j++] = aux;
  }

  return 0;
}
