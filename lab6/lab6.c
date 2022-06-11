#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double tabulation(double x_min, double x_max, double h);

int main(void) {
  double x_min = 1, x_max = 3, h = 0.1;
  double result = tabulation(x_min, x_max, h);
  return 0;
}

double tabulation(double x_min, double x_max, double h) {
  double y = 0;
  printf("Результат табулювання функції: \n");
  for (double x = x_min; x <= x_max + h; x = x + h) {
    y = sin(pow(x, 2));
    if (y > 0)
      printf("f(%.1f):  %.15lf\t\n", x + h, y);
    else
      printf("f(%.1f): %.15lf\t\n", x + h, y);
  }
  return y;
}
