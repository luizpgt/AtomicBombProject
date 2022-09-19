#ifndef TREE
#define TREE

#include <stdio.h>
#include <stdlib.h>

typedef struct _node Node;
struct _node {
  int key;
  Node *right;
  Node *left;
};

Node *setNode(int key);
Node *insertNode(Node *root, Node *new_node);
void inorder(Node *temp);
void postorder(Node *temp);
int getLevel(Node *root, Node *node, int lv);
void print_tree(FILE *stream, Node *node, size_t level);

#endif // TREE
