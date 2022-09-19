#include "queue.h"
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  Node *root = setNode(0);
  root = NULL;
  root ? printf("not null\n") : printf("current null\n");

  int i;
  for (i = 1; i < 16; i++) {
    root = insertNode(root, setNode(i));
  }

  printf("print in post order: ");
  postorder(root);
  printf("\n");

  print_tree(stdout, root, 0);
  //  printf("getting level of node key 8 (Expected 4): %d",
  //         getLevel(root, root->right, 1));

  // print_tree(Node *node, int lv)
}

int main4() {
  Node *root = setNode(0);
  root = NULL;
  root ? printf("not null\n") : printf("current null\n");

  root = insertNode(root, setNode(10));
  root = insertNode(root, setNode(11));
  root = insertNode(root, setNode(7));
  root = insertNode(root, setNode(9));
  root = insertNode(root, setNode(15));
  root = insertNode(root, setNode(8));

  printf("inorder print: ");
  inorder(root);
  printf("\n");

  printf("postorder print: ");
  // postorder(root);
  printf("\n");

  return 0;
}
int main3() {
  Node *root = setNode(0);
  root = NULL;
  root ? printf("not null\n") : printf("current null\n");

  root = insertNode(root, setNode(10));
  root = insertNode(root, setNode(11));
  root = insertNode(root, setNode(7));
  root = insertNode(root, setNode(9));
  root = insertNode(root, setNode(15));
  root = insertNode(root, setNode(8));

  printf("root element: %d\n", root->key);
  printf("root->left: %d\n", root->left->key);
  printf("root->right: %d\n", root->right->key);

  printf("7's right: %d\n",
         (root->right->right) ? root->right->right->key : -255);

  printf("7's left: %d\n", root->right->left ? root->right->left->key : -277);

  printf("11's left child: %d\n", root->left->left->key);
  printf("11's right child: %d\n", root->left->right->key);
  // printf("find eight: %d\n", root->left->left->left->key);

  return 0;
}

int main2() {
  Node *root = setNode(0);
  root = NULL;
  root ? printf("not null\n") : printf("current null\n");

  root = insertNode(root, setNode(10));
  root = insertNode(root, setNode(11));
  root = insertNode(root, setNode(7));
  root = insertNode(root, setNode(9));
  root = insertNode(root, setNode(15));
  root = insertNode(root, setNode(8));

  inorder(root);
  printf("\n");
  return 0;
}

int main1() {
  Node *root = setNode(1);
  printf("root's key = %d\n", root->key);

  root->right = setNode(2);
  root->left = setNode(3);
  root->left->left = setNode(4);

  printf("left node from root node: %d\n", root->left->key);
  printf("left node from left of root node: %d\n", root->left->left->key);

  return 0;
}
