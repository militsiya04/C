#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define White "\033[0;37m"
#define Blue "\033[0;34m"
#define Purple "\033[0;35m"

void tabulation(double array[], double x_min, double x_max, double h);

void tabulation(double tabulatedValues[], double x_min, double x_max,
                double h) {
  printf("\n%s", Blue);
  for (int i = 0; i < SIZE; i++) {
    tabulatedValues[i] = sin(x_min * x_min);
    x_min += h;
    printf(" sin((%.2lf)^2): %.15lf\t\n", x_min - 0.1, tabulatedValues[i]);
  }
  printf(White);

  for (int i = 0; i < SIZE - 1; i++) {
    for (int j = 0; j < SIZE - 1 - i; j++) {
      if (tabulatedValues[j] > tabulatedValues[j + 1]) {
        double temp = tabulatedValues[j];
        tabulatedValues[j] = tabulatedValues[j + 1];
        tabulatedValues[j + 1] = temp;
      }
    }
  }
  printf("\nSorted elements of function y = (sin (x^2)): \n\n");
  printf(Purple);
  for (int i = 0; i < SIZE; i++) {
    printf("%.15lf\t\n ", tabulatedValues[i]);
  }
}

int main(int argc, char *argv[]) {
  double array[SIZE];
  double x_min = 1, x_max = 3, h = 0.1;
  printf("\nResult of tabulation of the function y = (sin (x^2)): \n");
  tabulation(array, x_min, x_max, h);
  return 0;
}
