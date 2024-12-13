#include "tree.h"
#include "queue.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// TODO: free used memory

Node *setNode(int key) {
  Node *new = (Node *)malloc(sizeof(Node));
  new->key = key;
  new->right = NULL;
  new->left = NULL;
  return new;
}

Node *insertNode(Node *root, Node *new_node) { // causing leak of memory

  if (!root) { // if root node == NULL
    return new_node;
  }

  // setting up a queue to manage the nodes
  Queue *q = (Queue *)malloc(sizeof(Queue));
  q = NULL;
  q = push(q, setElement(root));

  // while q is not empty
  while (q) {
    Node *temp = front(q)->node; // assign the node on queue to temp var
    q = pop(q);
    if (temp->left != NULL)
      q = push(q, setElement(temp->left));
    else {
      temp->left = new_node;
      return root;
    }
    if (temp->right)
      q = push(q, setElement(temp->right));
    else {
      temp->right = new_node;
      return root;
    }
  }
  return root;
}

void inorder(Node *temp) {
  if (!temp)
    return;
  inorder(temp->left);
  printf("%d, ", temp->key);
  inorder(temp->right);
}

void postorder(Node *temp) {
  if (!temp)
    return;
  postorder(temp->right);
  printf("%d, ", temp->key);
  postorder(temp->left);
}

int getLevel(Node *root, Node *node, int lv) {
  if (!node)
    return 0;
  if (root == node)
    return lv;

  int downlevel = getLevel(root->left, node, lv++);
  if (downlevel != 0)
    return downlevel;

  downlevel = getLevel(root->right, node, lv++);
  return downlevel;
}

void print_tree(FILE *stream, Node *node, size_t level) {
  for (size_t i = 0; i < level; ++i)
    fputs(" ", stream);
  // fputs(node->key, stream);
  fprintf(stream, "%d", node->key);
  fputc('\n', stream);
  if (node->left)
    print_tree(stream, node->left, level + 1);
  if (node->right)
    print_tree(stream, node->right, level + 1);
}

/*
int existsOnList(Node *root, int key) {
  if (!root)
    return 0;
  if (root->key == key)
    return 1;
  existsOnList(root, key);
}
int findlv() {
  int lv, i;
  // for(i = 0; (sum + pow(2,i)) < )
  return lv;
}

void prettyprint(Node *root) {}
*/
