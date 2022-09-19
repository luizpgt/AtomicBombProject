#include <bits/stdc++.h>

int main() {
  int lr = 1, gtr = 0, i = 0, len = 1e6 + 1;
  char str[len];
  scanf("%s", str);

  while (str[i] != '\0') {
    if (str[i] == str[i - 1])
      lr++;
    else
      lr = 1;
    gtr = (lr > gtr ? lr : gtr);
    i++;
  }
  printf("%d", gtr);

  return 0;
}
