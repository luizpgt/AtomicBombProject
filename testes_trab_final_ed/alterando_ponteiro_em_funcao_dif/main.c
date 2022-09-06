#include <stdio.h>

double alterarIdade(double idade, int *id);

int main() {
  double idade = 15.3;
  int id_real = 5;
  int *id;
  id = &id_real;
  idade = alterarIdade(idade, &id_real);
  printf("id: %d | nova idade: %lf", *id, idade);
  return 0;
}

double alterarIdade(double idade, int *id) {
  //*id = *id + 1;
  (*id)++;
  return idade+2;
}
