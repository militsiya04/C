#include <stdio.h>
#include <stdlib.h>
#define SIZEOF 4

int main(int argc, char *argv[]) {
  int arrsize, methodOf, console;
  int middlearg = SIZEOF / 2;
  int oneDimArray_1[SIZEOF], oneDimArray_2[SIZEOF], oneDimArray_3[SIZEOF];
  int twoDimArray_1[SIZEOF][SIZEOF], twoDimArray_2[SIZEOF][SIZEOF + 1];
  int twoDimArray_3[SIZEOF][SIZEOF], twoDimArray_4[SIZEOF][SIZEOF + 1];
  int console_arr1[SIZEOF], console_arr2[SIZEOF][SIZEOF];
  int console_arr3[SIZEOF][SIZEOF + 1];

  printf("Оберіть (1): для вводу з клавіатури; \n(2): для добору випадкових "
         "чисел;\n(3): для вводу з консолі: ");
  scanf("%d", &methodOf);

  printf("Введіть (1) для роботи з одновімірним масивом\n");
  printf("Введіть (2) для роботи з двовімірним масивом: ");
  scanf("%d", &arrsize);
  if (methodOf == 1 && arrsize == 1) {
    for (int i = 0; i <= SIZEOF; i++) {
      if (i < SIZEOF) {
        printf(" Введіть значення елемента масиву: ");
        scanf("%d", &oneDimArray_1[i]);
      }
      if (i == SIZEOF) {
        printf("\n");
        for (int index_mass = 0; index_mass < SIZEOF; index_mass++) {
          printf("Значення елемента масиву: %d\n", oneDimArray_1[index_mass]);
        }
      }
    }
    printf("\n");
    for (int i = 0; i < SIZEOF; i++) {
      if (i < middlearg) {
        oneDimArray_2[i] = oneDimArray_1[i];
        printf("Масив із видаленим середнім арифметичним: %d\n",
               oneDimArray_2[i]);
      }
      if (i > middlearg) {
        oneDimArray_2[i] = oneDimArray_1[i];
        printf("Масив із видаленим середнім арифметичним: %d\n",
               oneDimArray_2[i]);
      }
    }
  }
  if (methodOf == 2 && arrsize == 1) {
    for (int i = 0; i <= SIZEOF; i++) {
      if (i < SIZEOF) {
        for (int j = 0; j < 5; j++) {
          oneDimArray_1[i] = rand() % 1000 - 1;
        }
      }
      if (i == SIZEOF) {
        for (int index_mass = 0; index_mass < SIZEOF; index_mass++) {
          printf("Значення елемента масиву: %d\n", oneDimArray_1[index_mass]);
        }
      }
    }
    for (int i = 0; i < SIZEOF; i++) {
      if (i < middlearg) {
        oneDimArray_2[i] = oneDimArray_1[i];
        printf("Масив із видаленим середнім арифметичним: %d\n",
               oneDimArray_2[i]);
      }
      if (i > middlearg) {
        oneDimArray_2[i] = oneDimArray_1[i];
        printf("Масив із видаленим середнім арифметичним: %d\n",
               oneDimArray_2[i]);
      }
    }
  }
  if (methodOf == 1 && arrsize == 2) {
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j < SIZEOF; j++) {
        printf("Введіть [%d][%d] елемент: ", i, j);
        scanf("%d", &twoDimArray_1[i][j]);
      }
    }
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j < SIZEOF; j++) {
        printf("[%d] ", twoDimArray_1[i][j]);
      }
      printf("\n");
    }
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j < SIZEOF; j++) {
        twoDimArray_2[i][j] = twoDimArray_1[i][j];
      }
    }
    printf("\nДодамо стовпець у кінець матриці \n");

    for (int i = 0; i < 1; i++) {
      for (int j = 0; j < SIZEOF; j++) {
        printf("Введіть [%d][%d] елемент: ", j, SIZEOF);
        scanf("%d", &twoDimArray_2[j][SIZEOF]);
      }
    }
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j < SIZEOF + 1; j++) {
        printf("[%d] ", twoDimArray_2[i][j]);
      }
      printf("\n");
    }
  }
  if (methodOf == 2 && arrsize == 2) {
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j < SIZEOF; j++) {
        twoDimArray_3[i][j] = rand() % 1000;
      }
    }
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j < SIZEOF; i++) {
        printf("[%d] ", twoDimArray_3[i][j]);
      }
      printf("\n");
    }
    printf("\nДодамо вивпадково згенерований стовпець у кінець матриці \n");

    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j < SIZEOF; j++) {
        twoDimArray_4[i][j] = twoDimArray_3[i][j];
      }
    }
    for (int i = 0; i < SIZEOF; i++) {
      twoDimArray_4[i][SIZEOF] = rand() % 1000;
    }
    printf("\n");
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j <= SIZEOF; j++) {
        printf("[%d] ", twoDimArray_4[i][j]);
      }
      printf("\n");
    }
  }
  if (arrsize == 1 && methodOf == 3) {
    console_arr1[0] = atof(argv[1]);
    console_arr1[1] = atof(argv[2]);
    console_arr1[2] = atof(argv[3]);
    console_arr1[3] = atof(argv[4]);
    for (int counter2 = 0; counter2 < SIZEOF; ++counter2) {
      printf("Значення елемента масиву: %d\n", console_arr1[counter2]);
    }
    for (int i = 0; i < SIZEOF; i++) {
      if (i < middlearg || i > middlearg) {
        if (i == middlearg) {
          continue;
        }
        oneDimArray_3[i] = console_arr1[i];
        printf("Масив із видаленим середнім арифметичним: %d\n",
               oneDimArray_3[i]);
      }
    }
  }
  if (methodOf == 3 && arrsize == 2) {
    console_arr2[0][0] = atof(argv[1]);
    console_arr2[0][1] = atof(argv[2]);
    console_arr2[0][2] = atof(argv[3]);
    console_arr2[0][3] = atof(argv[4]);
    console_arr2[1][0] = atof(argv[5]);
    console_arr2[1][1] = atof(argv[6]);
    console_arr2[1][2] = atof(argv[7]);
    console_arr2[1][3] = atof(argv[8]);
    console_arr2[2][0] = atof(argv[9]);
    console_arr2[2][1] = atof(argv[10]);
    console_arr2[2][2] = atof(argv[11]);
    console_arr2[2][3] = atof(argv[12]);
    console_arr2[3][0] = atof(argv[13]);
    console_arr2[3][1] = atof(argv[14]);
    console_arr2[3][2] = atof(argv[15]);
    console_arr2[3][3] = atof(argv[16]);
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j < SIZEOF; j++) {
        printf("[%d] ", console_arr2[i][j]);
      }
      printf("\n");
    }
    printf("\nДодамо стовпець у кінець матриці \n\n");
    console_arr3[0][0] = console_arr2[0][0];
    console_arr3[0][1] = console_arr2[0][1];
    console_arr3[0][2] = console_arr2[0][2];
    console_arr3[0][3] = console_arr2[0][3];
    console_arr3[1][0] = console_arr2[1][0];
    console_arr3[1][1] = console_arr2[1][1];
    console_arr3[1][2] = console_arr2[1][2];
    console_arr3[1][3] = console_arr2[1][3];
    console_arr3[2][0] = console_arr2[2][0];
    console_arr3[2][1] = console_arr2[2][1];
    console_arr3[2][2] = console_arr2[2][2];
    console_arr3[2][3] = console_arr2[2][3];
    console_arr3[3][0] = console_arr2[3][0];
    console_arr3[3][1] = console_arr2[3][1];
    console_arr3[3][2] = console_arr2[3][2];
    console_arr3[3][3] = console_arr2[3][3];
    console_arr3[3][4] = console_arr2[1][0];
    console_arr3[0][4] = console_arr2[2][1];
    console_arr3[1][4] = console_arr2[3][2];
    console_arr3[2][4] = console_arr2[2][3];
    console_arr3[3][4] = console_arr2[2][0];
    for (int i = 0; i < SIZEOF; i++) {
      for (int j = 0; j <= SIZEOF; j++) {
        printf("[%d] ", console_arr3[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}
