#include <stdio.h>
#include <time.h>

char university_title[10] = "KPI";
char department_title[15] = "APEPS";
char group_id[10] = "TR";
char student_surname[25] = "Mushkatyorov";
char student_name[10] = "Denys";
int groupnumber = 14;
double x = 2.773;
float z = 1.5;

int main(void) {
  printf("\nUniversity - %s\n", university_title);
  printf("Department - %s\n", department_title);
  printf("Group index - %s-%i\n", group_id, groupnumber);
  printf("Student's surname - %s\n", student_surname);
  printf("Name - %s\n", student_name);
  printf("\n%.3f\n", x);
  printf("%.1f\n", z);
  time_t t;
  time(&t);

  printf("\nThe time is : %s", ctime(&t));
  return 0;
}
