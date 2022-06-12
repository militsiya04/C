#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

typedef struct Patient {
  char family_name[SIZE];
  char first_name[SIZE];
  char patronymic[SIZE];
  char adress[SIZE];
  int med_card_number;
  int ins_card_number;
  char patient_number[SIZE];
  struct Patient *next;
} patient;

patient *create(char *data, char *data2, char *data3, char *data4, int data5,
                int data6);
void add_element(char *data, char *data2, char *data3, char *data4, int data5,
                 int data6, patient *head);
void delete_object(patient *head, int object, int counter_of_objects);
void print_list(patient *head);
void print_object(patient *head, int object);

patient *create(char *data, char *data2, char *data3, char *data4, int data5,
                int data6) {

  patient *tmp = (patient *)malloc(sizeof(patient));

  for (int i = 0; i < SIZE; i++)
    tmp->family_name[i] = data[i];
  for (int i = 0; i < SIZE; i++)
    tmp->first_name[i] = data2[i];
  for (int i = 0; i < SIZE; i++)
    tmp->patronymic[i] = data3[i];
  for (int i = 0; i < SIZE; i++)
    tmp->adress[i] = data4[i];

  tmp->med_card_number = data5;
  tmp->ins_card_number = data6;
  tmp->next = NULL;
  return (tmp);
}

void add_element(char *data, char *data2, char *data3, char *data4, int data5,
                 int data6, patient *head) {
  patient *tmp = (patient *)malloc(sizeof(patient));
  tmp = create(data, data2, data3, data4, data5, data6);
  patient *list = head;
  while (list->next != NULL)
    list = list->next;
  list->next = tmp;
}

void delete_object(patient *head, int object, int counter_of_objects) {
  patient *ptr_sec = head;
  patient *ptr_third = ptr_sec->next;

  if (object == counter_of_objects) {
    for (int i = 1; i < object; i++) {
      if (i == object - 1) {
        ptr_sec->next = NULL;
      }
      ptr_sec = ptr_sec->next;
    }
  } else {
    for (int i = 1; i < object; i++) {
      if (i == object - 1) {
        ptr_sec->next = ptr_third->next;
      }
      ptr_sec = ptr_sec->next;
      ptr_third = ptr_third->next;
    }
  }
}

void edit(patient *list, int object) {
  patient *list2 = list;
  for (int i = 1; i <= object; i++) {
    if (i == object) {
      printf("\nВведіть прізвище: ");
      scanf("%s", list2->family_name);
      printf("Введіть ім'я: ");
      scanf("%s", list2->first_name);
      printf("По батькові: ");
      scanf("%s", list2->patronymic);
      printf("Введіть адресу: ");
      scanf("%s", list2->adress);
      printf("Введіть номер медкарти: ");
      scanf("%d", &list2->med_card_number);
      printf("Введіть страхову картку: ");
      scanf("%d", &list2->ins_card_number);
      break;
    }
    list2 = list2->next;
  }
}

void display_list(patient *head) {
  patient *list = head;
  while (list != NULL) {
    printf("\nПрізвище: %s\n", list->family_name);
    printf("Ім'я: %s\n", list->first_name);
    printf("По батькові: %s\n", list->patronymic);
    printf("Адреса: %s\n", list->adress);
    printf("Номер мед-картки: %d\n", list->med_card_number);
    printf("Номер страхової картки: %d\n", list->ins_card_number);
    list = list->next;
  }
}

void display_object(patient *head, int object) {
  int counter = 1;
  patient *list2 = head;
  while (counter <= object) {
    if (counter == object) {
      printf("\nПрізвище: %s\n", list2->family_name);
      printf("Ім'я: %s\n", list2->first_name);
      printf("По батькові: %s\n", list2->patronymic);
      printf("Адреса: %s\n", list2->adress);
      printf("Номер мед-картки: %d\n", list2->med_card_number);
      printf("Номер страхової картки: %d\n", list2->ins_card_number);
    } else
      list2 = list2->next;
    counter++;
  }
}

int main() {
  char data[SIZE], data2[SIZE], data3[SIZE], data4[SIZE];
  int index, data5, data6, counter_of_objects;
  patient *list;

  do {
    printf("How many patients: ");
    scanf("%d", &counter_of_objects);
  } while (counter_of_objects < 1);

  for (int i = 0; i < counter_of_objects; i++) {
    printf("\nEnter the surname: ");
    scanf("%s", data);
    printf("Name: ");
    scanf("%s", data2);
    printf("Patronymic: ");
    scanf("%s", data3);
    printf("Adress (without spaces): ");
    scanf("%s", data4);
    printf("Medical card number: ");
    scanf("%d", &data5);
    printf("Insurance card number: ");
    scanf("%d", &data6);
    if (i == 0)
      list = create(data, data2, data3, data4, data5, data6);
    else
      add_element(data, data2, data3, data4, data5, data6, list);
  }
  patient *list2 = list;
  display_list(list);

  FILE *fp = fopen("patient.txt", "w");
  int counter = 0;
  while (list2 != NULL) {
    if (counter == 0)
      fprintf(fp, "%s\n", list2->family_name);
    else
      fprintf(fp, "\n\n%s\n", list2->family_name);
    fprintf(fp, "%s\n", list2->first_name);
    fprintf(fp, "%s\n", list2->patronymic);
    fprintf(fp, "%s\n", list2->adress);
    fprintf(fp, "%d\n", list2->med_card_number);
    fprintf(fp, "%d", list2->ins_card_number);
    list2 = list2->next;
    counter++;
  }
  struct Patient data_2[6 * counter_of_objects];
  counter = 0;

  fclose(fp);

  fp = fopen("patient.txt", "r");

  for (int i = 0; i < counter_of_objects; i++) {
    fscanf(fp, "%s", data_2[i].family_name);
    fscanf(fp, "%s", data_2[i].first_name);
    fscanf(fp, "%s", data_2[i].patronymic);
    fscanf(fp, "%s", data_2[i].adress);
    fscanf(fp, "%d", &data_2[i].med_card_number);
    fscanf(fp, "%d", &data_2[i].ins_card_number);
  }
  printf("\nData read from the file: \n");
  for (int i = 0; i < counter_of_objects; i++) {
    printf("\nPatient № %dXXX", (data_2[i].med_card_number) / 100);
    printf("\nSurname: %s\n", data_2[i].family_name);
    printf("Name: %s\n", data_2[i].first_name);
    printf("Patronymic: %s\n", data_2[i].patronymic);
    printf("Adress: %s\n", data_2[i].adress);
    printf("Medical card number: %d\n", data_2[i].med_card_number);
    printf("Insurance card number: %d\n", data_2[i].ins_card_number);
  }
  fclose(fp);
  int choice;
  do {
    printf("\n 1: Print patient data");
    printf("\n 2: Delete patient");
    printf("\n 3: Get list of patients");
    printf("\n 4: Edit patient data");
    printf("\n 5: End of program.\n");
    scanf("%d", &choice);
  } while (choice > 5 || choice < 1);

  switch (choice) {
  case 1:
    do {
      printf("Choose the patient (1 - %d): ", counter_of_objects);
      scanf("%d", &index);
    } while (index > counter_of_objects || index < 1);
    printf("\n#%d patient data: \n", index);
    display_object(list, index);
    break;

  case 2:
    do {
      printf("\nChoose the patient to delete (1 - %d): ", counter_of_objects);
      scanf("%d", &index);
    } while (index < 1 || index > counter_of_objects);

    if (index == 1)
      list = list->next;
    else
      delete_object(list, index, counter_of_objects);
    printf("\nObject #%d was successfully deleted: \n", index);
    display_list(list);
    break;

  case 3:
    printf("\nList of patients: \n");
    display_list(list);
    break;

  case 4:
    do {
      printf("\nChoose the patient to edit his data (1 - %d): ",
             counter_of_objects);
      scanf("%d", &index);
    } while (index < 1 || index > counter_of_objects);
    edit(list, index);
    printf("\nEdited list: \n");
    display_list(list);
    break;

  case 5:
    return 0;
    break;

  default:
    printf("There is no such operation.!\n");
  }
  return 0;
}
