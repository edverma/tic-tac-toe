#include <stdio.h>
#include <stdlib.h>

const int GRID_SIZE = 3;
const int BOARD_SIZE = GRID_SIZE * 2 + 1;

char** fillBoard(char* boardString[BOARD_SIZE], char xoMatrix[GRID_SIZE][GRID_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i += 2) {
    boardString[i] = "|---|---|---|\n";
    if (i+1 < BOARD_SIZE) {
      boardString[i+1] = calloc(GRID_SIZE*3 + GRID_SIZE+1, sizeof(char*));
      sprintf(boardString[i+1], "| %c | %c | %c |\n", xoMatrix[i/2][0], xoMatrix[i/2][1], xoMatrix[i/2][2]);
    }
  }

  return boardString;
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
  return 0;
}
