#include <bits/stdc++.h>

int main() {
  int i = 8;
  int *j = &i;
  char ch = NULL;

  std::cout << *j;
  j = NULL;
  if (j)
    std::cout << *j;
  else
    std::cout << "j is currently null\n";
  return 0;
}
