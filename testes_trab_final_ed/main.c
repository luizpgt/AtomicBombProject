#include <stdio.h>
#include <stdlib.h>

int diminuir_estoque(int qtd_estoque, int diminuir);

int main() {
  double n = 0.1;
  printf("valor de n: %.14lf\n", n);
  n *= 100;
  n = (int)n;
  printf("valor de n: %d\n", (int)n);
  n = (double)n;
  printf("valor de n: %.14lf\n", n);
  n /= 100;
  printf("valor de n: %.14lf\n", n);
  return 0;
}
int main4() {
  double n1 = 0.3, n2 = 0.2;
  double n = n1 - n2;
  printf("valor de n: %.12lf\n", n);

  n1 *= 100;
  n2 *= 100;
  n = (n1 - n2) / 100;
  printf("valor de n: %.12lf\n", n);
  return 0;
}

int main3() {
  printf("teste numeros double\n");
  double n = 0.2, n2 = 0.1;
  printf("valor soma dos n: %.9lf\n", n + n2);
  return 0;
}

int main2() {
  double preco;
  preco = 1.2;
  printf("valor preco: %lf\n", preco);
  preco *= 100;

  printf("valor preco: %lf\n", preco);
  return 0;
}
int main1() {
  int qtd_estoque = 5;
  qtd_estoque = diminuir_estoque(qtd_estoque, 5);
  printf("quantia em estoque: %d\n", qtd_estoque);
  qtd_estoque = diminuir_estoque(qtd_estoque, -1);
  printf("quantia em estoque: %d\n", qtd_estoque);

  printf("atomicbombproject\n");
  return 0;
}

int diminuir_estoque(int qtd_estoque, int diminuir) {
  qtd_estoque += diminuir;
  return qtd_estoque;
}
