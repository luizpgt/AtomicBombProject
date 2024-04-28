#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, odd = 0, opos, k;
  int alf[26] = {0};
  char str[1000000];
  char c;
  scanf("%s", str);

  /*
  A = 65
  Z = 90
  65 - 65 = 0 = A
  90 - 65 = 25 = Z
  0 ... 25 = 26 letters
  */

  i = 0;
  while (str[i]) {
    c = str[i];
    if (alf[c - 65] % 2)
      odd--;
    else
      odd++;
    alf[c - 65] += 1;
    i++;
  }

  if ((i % 2 && odd != 1) || (i % 2 == 0 && odd)) {
    cout << "NO SOLUTION";
    return 0;
  }

  // print arranged;
  i = 0;
  // print first 1/2
  while (i < 26) {
    if (alf[i]) {
      if (!(alf[i] % 2))
        alf[i] /= 2;
      else {
        opos = i++;
        continue;
      }
      for (k = 1; k <= alf[i]; k++)
        cout << (char)(i + 65);
    }
    i++;
  }
  // print the odd char if exists
  if (odd) {
    while (alf[opos]--) {
      cout << (char)(opos + 65);
    }
  }
  i = 25;
  // print the other half
  while (i >= 0) {
    if (alf[i]) {
      for (k = 1; k <= alf[i]; k++)
        cout << (char)(i + 65);
      alf[i] = 0;
    }
    i--;
  }

  return 0;
}
