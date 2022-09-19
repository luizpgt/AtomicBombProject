#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int i;
  Queue *front = (Queue *)malloc(sizeof(Queue));
  front = NULL;

  srand(time(0));
  for (i = 0; i < 10; i++)
    front = push(front, setElement(rand() % 101));

  printf("first element added value = front = %d\n", front->value);
  // front = pop(front);
  // printf("first element added value = front = %d\n", front->value);
  // front = push(front, setElement(55));
  printf("last element added value = back = %d\n", back(front)->value);

  printall(front);
  printf("\n");

  for (i = 0; i < 10; i++)
    front = pop(front);
  printf("value of front element = %d\n", front ? front->value : -1);
  return 0;
}
