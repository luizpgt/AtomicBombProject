#ifndef STACK_H
#define STACK_H

typedef struct _stack Stack;
struct _stack {
  int disk;
  Stack *next;
};

Stack *set_stack();
void move_disk(Stack **top_sender, Stack **top_receiver);
int is_solved(Stack *third, int numof_disks);
Stack *populate_stack(Stack *rod, int numof_disks);
void print_stack(Stack *rod);
void errorUtils(int key);

#endif // !STACK_H
