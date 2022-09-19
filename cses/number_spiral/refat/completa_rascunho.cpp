/*
A number spiral is an infinite grid whose upper-left square has number 1. Here
are the first five layers of the spiral:

Your task is to find out the number in row y and column x.

Input

The first input line contains an integer t: the number of tests.

After this, there are t lines, each containing integers y and x.

Output

For each test, print the number in row y and column x.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, i, k;
  cin >> n;

  struct _pos {
    ll line, col;
  };

  struct _pos ar[n];
  struct _pos aux;

  for (i = 0; i < n; i++) {
    cin >> ar[i].line >> ar[i].col;
    /*
    for (k = i; // insertion order
         k > 0 && (ar[k].line < ar[k - 1].line || ar[k].col < ar[k - 1].col);
         k--) {
      aux.line = ar[k].line;
      aux.col = ar[k].col;
      ar[k].line = ar[k - 1].line;
      ar[k].col = ar[k - 1].col;
      ar[k - 1].line = aux.line;
      ar[k - 1].col = aux.col;
    }
  */
  }

  for (i = 0; i < n; i++)
    cout << "i: " << i << " line : " << ar[i].line << " col: " << ar[i].col
         << "\n";

  ll value, col, line;
  for (i = 0; i < n; i++) {
    // se a linha for maior que a coluna
    if (ar[i].line >= ar[i].col) {
      // se linha for a maior, e for par
      if (ar[i].line % 2 == 0) {
        value = ar[i].line * ar[i].line;
        col = 0;
        while (col < ar[i].col - 1) {
          value--;
          col++;
        }
        cout << "value ::: " << value << "\n";
      } else { // se linha for a maior e for impar
        value = (ar[i].line - 1) * (ar[i].line - 1) + 1;
        col = 0;
        while (col < ar[i].col - 1) {
          value++;
          col++;
        }
        cout << "value ::: " << value << "\n";
      }
    }
    // se coluna for maior e for par
    else {
      if (ar[i].col % 2 == 0) {
        value = (ar[i].col - 1) * (ar[i].col - 1) + 1;
        line = 0;
        while (line < ar[i].line - 1) {
          value++;
          line++;
        }
        cout << "value :: " << value << "\n";
        // se coluna for maior e for impar
      } else {
        value = ar[i].col * ar[i].col;
        line = 0;
        while (line < ar[i].line - 1) {
          value--;
          line++;
        }
        cout << "value :: " << value << "\n";
      }
    }
  }

  return 0;
}
