#include <stdio.h>
#include <stdlib.h>
#define LEN 6

void insert_sort(int *array, int arr_len);

int main() {
  int array[LEN] = {5, 2, 5, 6, 1, 3};
  insert_sort(array, LEN);

  return 0;
}
void insert_sort(int *array, int arr_len) {
  int j, i, chave;
  for (j = 1; j < arr_len; j++) {
    chave = array[j];
    i = j - 1;
    while (i > 0 && array[i] > chave) {
      array[i + 1] = array[i];
      i--;
    }
    array[i + 1] = chave;
  }
  for (i = 0; i < arr_len; i++)
    printf("%d : value %d\n", i, array[i]);
}
