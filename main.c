#include <stdio.h>
#include <stdlib.h>

const int GRID_SIZE = 3;
const int BOARD_SIZE = GRID_SIZE * 2 + 1;
const int BOARD_LENGTH = GRID_SIZE * 3 + GRID_SIZE + 1;

void fillBoard(char* boardString[BOARD_SIZE], char xoMatrix[GRID_SIZE][GRID_SIZE]) {
  for (int i=0; i<GRID_SIZE; i++) {
    for (int j=0; j<GRID_SIZE; j++) {
      printf("\nxoMatrix[%d][%d]: %c", i, j, xoMatrix[i][j]);
    }
  }
  for (int i = 0; i < BOARD_SIZE; i += 2) {
    boardString[i] = "\n|---|---|---|";
    if (i+1 < BOARD_SIZE) {
      boardString[i+1] = calloc(BOARD_LENGTH, sizeof(char*));
      sprintf(boardString[i+1], "\n| %c | %c | %c |", xoMatrix[i/2][0], xoMatrix[i/2][1], xoMatrix[i/2][2]);
    }
  }
}

void printBoard(char* boardString[BOARD_SIZE]) {
  for (int i=0; i < BOARD_SIZE; i++) {
    printf("%s", boardString[i]);
    if (i % 2 != 0) {
	free(boardString[i]);
    }
  }
}

int main() {
  char* boardString[BOARD_SIZE];
  char xoMatrix[GRID_SIZE][GRID_SIZE] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
  fillBoard(boardString, xoMatrix);
  printBoard(boardString);

  char winner = ' ';
  char currentPlayer = 'X';
  while (winner == ' ') {
    printf("\n%c make your move: ", currentPlayer);
    printf("\nx coordinate: ");
    int xCoordinate; int yCoordinate;
    scanf("%d", &xCoordinate);
    printf("\ny coordinate: ");
    scanf("%d", &yCoordinate);
    xoMatrix[xCoordinate][yCoordinate] = currentPlayer;
    putchar(xoMatrix[xCoordinate][yCoordinate]);

    if (currentPlayer == 'X') {
      currentPlayer = 'O';
    } else {
      currentPlayer = 'X';
    }

    fillBoard(boardString, xoMatrix);
    printBoard(boardString);
  }

  return 0;
}
