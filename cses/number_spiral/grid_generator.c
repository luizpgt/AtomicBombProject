#include <stdio.h>
#define LINHAS 60
#define COLUNAS 60

int main() {
  printf("atomic bomb project\n");

  int i, j, contador = 1, linha, coluna;
  int grid[LINHAS][COLUNAS] = {0};
  linha = coluna = 0;
  // grid[0][0] = 0;
  // grid[1][1] = 1;
  // grid[2][2] = 2;
  // grid[3][3] = 3;
  // grid[4][4] = 4;

  // grid[linha][++coluna] = ++contador;
  printf("grid[1][2]: %d\n", grid[1][2]);
  printf("grid[1][0]: %d\n", grid[1][0]);
  // grid[0][0] = 55;

  // printing grid :::
  for (i = 0; i < LINHAS; i++)
    for (j = 0; j < COLUNAS; j++) {
      printf("linha: %d coluna: %d --- %d [%p]\n", i, j, grid[i][j],
             &grid[i][j]);
    }
  /*
    // printing right way:::
    for (i = 0; i < LINHAS; i++)
      for (j = 0; j < COLUNAS; j++) {
        printf("%d ", grid[i][j]);
        if (j == 5)
          printf("\n");

      }
    */
  int turn, move_down, move_right;
  turn = move_down = move_right = 0;
  int godown, goup, goright, goleft;
  godown = goup = goright = goleft = 0;

  linha = coluna = 0;
  contador = 0;
  grid[linha][coluna] = ++contador;

  // while (linha < LINHAS && coluna < COLUNAS) {
  while (contador < LINHAS * COLUNAS) {
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

  // printing right way:::
  for (i = 0; i < LINHAS; i++)
    for (j = 0; j < COLUNAS; j++) {
      // if (grid[i][j] < 10)
      //   printf("0%d ", grid[i][j]);
      // else
      printf("%03d ", grid[i][j]);
      if (j == COLUNAS - 1)
        printf("\n");
    }
  return 0;
}
