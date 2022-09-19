#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct location {
  ll line, column;
};

// TODO: what if max_pos = 0?
int main() {
  ll i = 0, j = 0, contador, linha, coluna;
  ll max_pos = 0;
  ll num_of_tests;
  // scanf("%d", &num_of_tests);
  cin >> num_of_tests;
  ll results[num_of_tests];
  struct location pos_array[num_of_tests];
  while (i < num_of_tests) {
    // scanf("%d %d", &pos_array[i].line, &pos_array[i].column);
    cin >> pos_array[i].line >> pos_array[i].column;
    if (pos_array[i].line > max_pos || pos_array[i].column > max_pos)
      max_pos = pos_array[i].line > pos_array[i].column ? pos_array[i].line
                                                        : pos_array[i].column;
    i++;
  }

  ll grid[max_pos][max_pos + 1];

  ll godown, goup, goright, goleft;
  godown = goup = goright = goleft = 0;

  linha = coluna = 0;
  contador = 0;
  grid[linha][coluna] = ++contador;

  // grid generator
  while (contador < max_pos * max_pos) {
    if (linha == 0 && godown == 0) {
      grid[linha][++coluna] = ++contador;
      godown++;
      goup = goleft = goright = 0;
      continue;
    } else if (coluna == linha && goleft == 0 && goup == 0) {
      if (godown) {
        godown = 0;
        goleft++;
      } else if (goright) {
        goright = 0;
        goup++;
      }
      continue;
    } else if (coluna == 0) {
      grid[++linha][coluna] = ++contador;
      grid[linha][++coluna] = ++contador;
      goright++;
      goup = goleft = godown = 0;
      continue;
    }

    if (godown) {
      grid[++linha][coluna] = ++contador;
    } else if (goup) {
      grid[--linha][coluna] = ++contador;
    } else if (goleft) {
      grid[linha][--coluna] = ++contador;
    } else if (goright) {
      grid[linha][++coluna] = ++contador;
    }
  }
  /*
    // printing right way:::
    for (i = 0; i < max_pos; i++)
      for (j = 0; j < max_pos; j++) {
        cout << grid[i][j];
        // printf("%03d ", grid[i][j]);
        if (j == max_pos - 1)
          printf("\n");
      }

      */
  // populate results array
  i = 0;
  while (i < num_of_tests) {
    linha = pos_array[i].line - 1;
    coluna = pos_array[i].column - 1;
    results[i] = grid[linha][coluna];
    i++;
  }

  // print results
  for (i = 0; i < num_of_tests; i++)
    cout << results[i] << "\n";
  // printf("%d\n", results[i]);

  return 0;
}
