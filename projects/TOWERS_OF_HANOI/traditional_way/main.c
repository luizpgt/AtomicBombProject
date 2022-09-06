#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_DISKS 4
#define NUM_OF_RODS 3

// SOLVED: avoid crash when player try to move from an empty rod
// TODO: clear memory after puzzle solved [not really important here]
/* TODO: use >< to control which is the sender/receiver rod
        [ 1 < 2 first rod receives the 2nd rod's top ] */
// TODO: better way to print the stacks

int main() {
  int sender, receiver, i = 0;

  Stack *st = (Stack *)malloc(sizeof(Stack));
  Stack *nd = (Stack *)malloc(sizeof(Stack));
  Stack *rd = (Stack *)malloc(sizeof(Stack));
  st = NULL;
  nd = NULL;
  rd = NULL;

  // populate first rod:
  st = populate_stack(st, NUM_OF_DISKS);
  Stack *array_of_rods[NUM_OF_RODS] = {st, nd, rd};
  char *_posfix[] = {"st", "nd", "rd"};

  while (i < NUM_OF_RODS) {
    printf("printing all %d%s stack (rod) ", (i + 1), _posfix[i]);
    print_stack(array_of_rods[i++]);
    printf("\n");
  }

  /*
  printf("printing all first stack (rod)");
  print_stack(st);
  printf("\n");

  printf("printing all first stack (rod)");
  print_stack(array_of_rods[0]);
  printf("\n");

  printf("printing all sec stack (rod)");
  print_stack(array_of_rods[1]);
  printf("\n");

  printf("printing all third stack (rod)");
  print_stack(array_of_rods[2]);
  printf("\n");
  */

  printf("how to play:\nmove from 1st rod to 2nd rod: 1 2\n");
  // player wins when move all the plates (in order) to the last rod
  while (!is_solved(array_of_rods[2], NUM_OF_DISKS)) {
    scanf("%d %d", &sender, &receiver);
    move_disk(&(array_of_rods[sender - 1]), &(array_of_rods[receiver - 1]));

    printf("printing all first stack (rod) ");
    print_stack(array_of_rods[0]);
    printf("\n");

    printf("printing all sec stack (rod) ");
    print_stack(array_of_rods[1]);
    printf("\n");

    printf("printing all third stack (rod) ");
    print_stack(array_of_rods[2]);
    printf("\n");
  }
  if (is_solved(array_of_rods[2], NUM_OF_DISKS))
    printf("--->puzzle solved!<---\n");
  printf("printing all third stack (rod) ");
  print_stack(array_of_rods[2]);
  printf("\n");
  return 0;
}
