#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

void delete_el(int index, int *array, int size);

void delete_el(int index, int *array, int size) {

  for (int i = index; i < size; i++) {
    int j = i + 1;
    array[i] = array[j];
  }

  for (int i = 0; i < size - 1; i++)
    printf("%s[%i] element = %d \n", (i == 0) ? "\n" : "", i + 1, array[i]);
}

int main() {
  int oneDimSize, key, index = 0;

  printf("\t\t\t\t\tTask 1\n\nEnter the number of elements in oneDimArray: ");
  scanf("%d", &oneDimSize);

  int *array = calloc(oneDimSize, sizeof *array);

  for (int i = 0; i < oneDimSize; i++) {
    printf("%sEnter [%i] element: ", (i == 0) ? "\n" : "", i + 1);
    scanf("%d", &array[i]);
  }

  for (int i = 0; i < oneDimSize; i++)
    printf("%s[%i] element = %d \n", (i == 0) ? "\n" : "", i + 1, array[i]);

  printf("\nEnter the key (1 - %d): ", oneDimSize);
  scanf("%d", &key);
  if (key <= oneDimSize && key > 0) {
   while (array[index] != key)
    index++;
    delete_el(index, array, oneDimSize); }
  else
    printf("The key is wrong.");

  printf("\n\t\t\t\t\tTask2\n");

  int row = 3, col = 3, i, j, count = 0;
  int(*arr)[col] = calloc(row, sizeof *arr);

  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++)
      (arr)[i][j] = ++count;
  printf("\nInitial array:\n");
  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++)
      printf("%d\t%s", (arr)[i][j], (j == col - 1) ? "\n" : "");
  row++;
  for (i = 0; i < row - 1; i++)
    (arr)[3][i] = ++count;

  printf("\nArray with added row:\n");
  for (i = 0; i < row; i++)
    for (j = 0; j < col; j++)
      printf("%d\t%s", (arr)[i][j], (j == col - 1) ? "\n" : "");
  free(arr);
  return 0;
}
