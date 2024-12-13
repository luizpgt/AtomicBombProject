#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ll n, i, k, value, col, line;
  cin >> n;

  struct _pos {
    ll line, col;
  } Pos;

  struct _pos ar[n];
  struct _pos aux;

  for (i = 0; i < n; i++)
    cin >> ar[i].line >> ar[i].col;

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
      } else { // se linha for a maior e for impar
        value = (ar[i].line - 1) * (ar[i].line - 1) + 1;
        col = 0;
        while (col < ar[i].col - 1) {
          value++;
          col++;
        }
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
        // se coluna for maior e for impar
      } else {
        value = ar[i].col * ar[i].col;
        line = 0;
        while (line < ar[i].line - 1) {
          value--;
          line++;
        }
      }
    }
    cout << value << "\n";
  }

  return 0;
}
