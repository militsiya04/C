#include <stdio.h>
#include <stdlib.h>

struct Patient {
  char family_name[50];
  char first_name[50];
  char patronymic[50];
  char adress[50];
  int med_card_number;
  int ins_card_number;
};

int main(void) {
  struct Patient data[] = {{"Kazantseva",       "Olena",  "Petrivna",
                           "Lomonosova-133",   249155,   23888},
                           {"Melnychenko",      "Oleh",   "Serhiyovych",
                           "Yevropeyska-34/b", 272164,   21755},
                           {"Kryvenko",         "Stepan", "Volodymyrovych",
                           "Shevchenka-17/a",  238129,   21982}};
  struct Patient data_2[sizeof(data) / sizeof(data[0])];
  FILE *fp = fopen("patient.txt", "w");
  for (int i = 0; i < 3; i++)
    fprintf(fp, "%s\t%s\t%s\t%s\t%d\t%d\n", 
          data[i].family_name, data[i].first_name, data[i].patronymic,
          data[i].adress, data[i].med_card_number, data[i].ins_card_number);
 
  fclose(fp);
  fp = fopen("patient.txt", "r");
 
  for (int i = 0; i < 3; i++)
    fscanf(fp, "%s %s %s %s %d %d", 
           data_2[i].family_name, data_2[i].first_name, data_2[i].patronymic,
           data_2[i].adress, &data_2[i].med_card_number, &data_2[i].ins_card_number);

  for (int i = 0; i < 3; i++)
    printf("%sPatient #%iXXX\nFamily name: %s\nFirst name: %s\nPatronymic: "
           "%s\nAdress: "
           "%s\nMedical card index: %d\nInsuranse card index: %d\n\n",
           (i == 0) ? "\nPatients data:\n\n" : "",
           data_2[i].med_card_number / 1000, data_2[i].family_name, data_2[i].first_name,
           data_2[i].patronymic, data_2[i].adress, data_2[i].med_card_number, data_2[i].ins_card_number);
  fclose(fp);
  return 0;
}
