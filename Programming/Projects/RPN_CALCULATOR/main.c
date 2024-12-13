#include <stdio.h>

double operation(int num, int num2, char op);
long int topow(int num, int num2);
// TODO : add variables to store values of previous operations

int main() {
  int num, num2;
  char op;

  printf("suported operations: +, -, *, /, %%, ^.\n");
  scanf("%d %d %c", &num, &num2, &op);
  printf("final result = %.1lf\n", operation(num, num2, op));
  return 0;
}

double operation(int num, int num2, char op) {
  double res = 0;
  switch (op) {
  case '+':
    res = num + num2;
    break;
  case '-':
    res = num - num2;
    break;
  case '*':
    res = num * num2;
    break;
  case '/':
    num2 != 0 ? res = num * 1.0 / num2 : 0;
    break;
  case '%':
    num2 ? res = num % num2 : 0;
    break;
  case '^':
    res = topow(num, num2);
    break;
  default:
    printf("invalid operation\n");
  }
  return res;
}

long int topow(int num, int num2) {
  long int res = 1;
  for (; num2 > 0; num2--)
    res *= num;
  return res;
}
