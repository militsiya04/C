#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 5

int main(int argc, char *argv[]) {
  char univ[40] = "Igor Sikorsky Kyiv Polytechnic Institute";
  char department[8] = "APEPS";
  char group_index[5] = "TR-14";
  char surname[12] = "Mushkatyorov";
  char buff[16];

  int variant_number = 8, counter = 0, twoDimArray[SIZE][SIZE];
  int p = 17;
  bool locker = true;

  srand(time(NULL));

  FILE *file = fopen("t.txt", "w");

  if (file == NULL) {
    printf("Failure!\n");
    return 1;
  } else
      printf("File was succesfully created!\n");

  int check = (fprintf(file,
                       " %s, department %s, group %s, %s, list number № "
                       "%d.\n\nMatrix of numbers: \n",
                       univ, department, group_index, surname, variant_number));

  if (check > 0) {
    printf("Data was sucessfully written into the file.\n");
  }

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      twoDimArray[i][j] = rand() % 50 - 1;
      check = fprintf(file, "%d ", twoDimArray[i][j]);
      if (check > 0 && locker) {
        printf("Matrix was successfully written into file.\n");
        locker = false;
      }
    }
    fprintf(file, "\n");
  }
  fclose(file);

  file = fopen("t.txt", "r");
  FILE *file2 = fopen("t.bak", "w");

  while (fgetc(file) != EOF) {
    fscanf(file, "%s", buff);
    fprintf(file2, "%s ", buff);
    counter++;
    if (counter == 14)
      fprintf(file2, "\n\n");
    else if (counter == p && p < 42) {
      fprintf(file2, "\n");
      p += SIZE;
    } else if (counter == 42)
      fclose(file);
  }
  
  fclose(file2);
  return 0;
}
