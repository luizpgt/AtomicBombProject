#ifndef QUEUE_H
#define QUEUE_H

#include "tree.h"

typedef struct _queue Queue;
struct _queue {
  Node *node;
  Queue *next;
};

Queue *setElement(Node *node);
Queue *push(Queue *first, Queue *new_el); // inserts into queue

Queue *front(Queue *front); // return the front element (first added between the
                            // elements)
Queue *back(
    Queue *front); // return the back elements (last added between the elements)

Queue *pop(Queue *front); // removes an element from the queue
void printall(Queue *front);

#endif // QUEUE_H
