#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  float x = 0, a, y;

  if (x == 0) {
    if (argc == 3) {
      x = atof(argv[1]);
      a = atof(argv[2]);
    } else {
      printf("Введіть значення змінної х: \n");
      scanf("%f", &x);
      printf("Введіть значення змінної а: \n");
      scanf("%f", &a);
    }
  }
  if (x > 6) {
    y = cos(a * x);
    printf("\nРезультат роботи програми:\ny = %f\n", y);
  } else if (x < 6) {
    y = fabsf(a + x);
    printf("\nРезультат роботи програми:\ny = %f\n", y);
  } else if (x == 6) {
    printf("Введене значення не задовільне, помилка\n");
  }
  return 0;
}
