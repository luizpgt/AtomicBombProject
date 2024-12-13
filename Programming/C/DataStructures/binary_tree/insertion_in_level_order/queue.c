#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

Queue *setElement(Node *node) {
  Queue *new_el = (Queue *)malloc(sizeof(Queue));
  // new_el->value = value;
  new_el->node = node;
  new_el->next = NULL;
  return new_el;
}

Queue *push(Queue *front, Queue *new_el) {
  if (!front) // if none elements on queue
    return new_el;
  Queue *last_el = back(front); // last_el = last added
  last_el->next = new_el;
  return front;
}

Queue *front(Queue *front) { return front; }

Queue *back(Queue *front) {
  if (front) // if front != NULL
    for (; front->next != NULL; front = front->next)
      ;
  return front;
}

Queue *pop(Queue *front) {
  if (!front) // if front NULL
    return front;
  Queue *aux = front->next;
  free(front);
  return aux;
}

void printall(Queue *front) {
  if (!front)
    return;
  printall(front->next);
  // printf("%d, ", front->value);
}
