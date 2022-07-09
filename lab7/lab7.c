#include <stdio.h>
#include <stdlib.h>
#define Cyan "\033[0;36m"
#define SIZE 3

void printTwoDimArray(int array[SIZE][SIZE]);

void printTwoDimArray(int array[SIZE][SIZE]) {
  printf(Cyan);
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) 
      printf("%d", array[i][j]);
    printf("\n");
  }
}

int main(int argc, char *argv[]) {

  int twoDimArray[SIZE][SIZE];

  if (argc == 10) {
    twoDimArray[0][0] = atoi(argv[1]);
    twoDimArray[0][1] = atoi(argv[2]);
    twoDimArray[0][2] = atoi(argv[3]);
    twoDimArray[1][0] = atoi(argv[4]);
    twoDimArray[1][1] = atoi(argv[5]);
    twoDimArray[1][2] = atoi(argv[6]);
    twoDimArray[2][0] = atoi(argv[7]);
    twoDimArray[2][1] = atoi(argv[8]);
    twoDimArray[2][2] = atoi(argv[9]);

    printf("\nInitial two-dim array:\n\n");

    printTwoDimArray(twoDimArray);

    for (int i = 0; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        if (i == 0) {
          int buff = twoDimArray[i][j];
          twoDimArray[i][j] = twoDimArray[i + 2][j];
          twoDimArray[i + 2][j] = buff;
        }
      }
    }
    printf("\nHorizontally transformed array:\n\n");
    printTwoDimArray(twoDimArray);
  } else
    printf("The number of parameters entered must be 10:\n1 - /main, 2:10 - "
           "elements of matrix");
  return 0;
}
