#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// set_stack returns a blank stack;
// abstraction for the rods on the original game
Stack *set_stack() {
  Stack *new = (Stack *)malloc(sizeof(Stack));
  new->disk = 0;
  new->next = NULL;
  return new;
}

Stack *populate_stack(Stack *rod, int numof_disks) {
  int i = 1;
  if (!rod) {
    rod = set_stack();
    rod->disk = numof_disks;
  }
  i = --numof_disks;
  for (; rod->disk > 1; i--) {
    Stack *new = set_stack();
    new->disk = i;
    new->next = rod;
    rod = new;
  }
  return rod;
}

void errorUtils(int key) {
  printf("### ERR: ");
  switch (key) {
  case 0:
    printf("cant put disk on top of smaller disk\n");
    break;
  default:
    printf("an error ocurred\n");
  }
}

#define smaller(top_sender, top_receiver)                                      \
  ((top_sender->disk) < (top_receiver->disk)) ? 1 : 0

// move disk from one stack to another
void move_disk(Stack **top_sender, Stack **top_receiver) {
  Stack *aux;
  if (*top_sender == NULL)
    return errorUtils(2);
  if (*(top_receiver) == NULL || smaller((*top_sender), (*top_receiver))) {
    aux = (*top_sender)->next;
    (*top_sender)->next = (*top_receiver);
    (*top_receiver) = (*top_sender);
    (*top_sender) = aux;
  } else {
    errorUtils(0); // on top of smaller disk
  }
}

int is_solved(Stack *third, int numof_disks) {
  int is = 0;
  if (third) {
    for (; third != NULL; third = third->next) {
      is++;
    }
    return (is == numof_disks ? 1 : 0);
  }
  return is;
}

void print_stack(Stack *rod) {
  if (!rod)
    return;
  print_stack(rod->next);
  printf("%d ", rod->disk);
}
