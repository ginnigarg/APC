#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
  int rollNo;
  int age;
  char name[10];
}Student;

void printArray(Student[], int);

int compareByName(const void* a, const void* b) {
  return strcmp((*(Student *)a).name, (*(Student *)b).name);
}

int compareByAge(const void* a, const void* b) {
  return (*(Student *)a).age - (*(Student *)b).age;
}

int compareByRoll(const void* a, const void* b) {
  return (*(Student *)a).rollNo - (*(Student *)b).rollNo;
}

void swap(void* arr, int i, int j) {
  int temp1;
  char temp2[20];

//  printf("Roll : %d %d ",((Student *)(arr) + i)->rollNo, ((Student *)(arr) + j)->rollNo);
  temp1 = ((Student *)(arr) + i)->rollNo;
  ((Student *)(arr) + i)->rollNo = ((Student *)(arr) + j)->rollNo;
  ((Student *)(arr) + j)->rollNo = temp1;
//  printf("%d %d\n", ((Student *)(arr) + i)->rollNo, ((Student *)(arr) + j)->rollNo);

//  printf("Age : %d %d ", ((Student *)(arr) + i)->age, ((Student *)(arr) + j)->age);
  temp1 = ((Student *)(arr) + i)->age;
  ((Student *)(arr) + i)->age = ((Student *)(arr) + j)->age;
  ((Student *)(arr) + j)->age = temp1;
//  printf("%d %d\n", ((Student *)(arr) + i)->age, ((Student *)(arr) + j)->age);

//  printf("Name %s %s", ((Student *)(arr) + i)->name, ((Student *)(arr) + j)->name);
  strcpy(temp2, ((Student *)(arr)+ i)->name);
  strcpy(((Student *)(arr) + i)->name, ((Student *)(arr) + j)->name);
  strcpy(((Student *)(arr) + j)->name, temp2);
//  printf("%s %s\n", ((Student *)(arr) + i)->name, ((Student *)(arr) + j)->name);
}

void quickSort(void* arr, int start, int end, int (*comp)(const void*, const void*)) {
  if(start >= end) return;
  int pivot = start, it = start;
  for(int i = start + 1; i <= end; i++){
    if(comp(((Student *)(arr) + i), ((Student *)(arr) + pivot)) <= 0) {
//      printf("Here : ");
      swap(arr, i, ++it);
    }
  }
  swap(arr, pivot, it);
//  printArray(arr, 4);
  quickSort(arr, start, it - 1, comp);
  quickSort(arr, it + 1, end, comp); 

}

void printArray(Student arr[], int size) {
  for(int i = 0; i < size; i++) {
    printf("%d %s %d\n", arr[i].rollNo, arr[i].name, arr[i].age);
  }
  printf("\n");
}


int main() {
  Student s[4];
  
  s[0].rollNo = 10;
  s[1].rollNo = 30;
  s[2].rollNo = 20;
  s[3].rollNo = 40;

  s[0].age = 25;
  s[1].age = 20;
  s[2].age = 15;
  s[3].age = 10;

  strcpy(s[0].name, "Guneet");
  strcpy(s[1].name, "Ayush");
  strcpy(s[2].name, "Yuwin");
  strcpy(s[3].name, "Hardik");

  int (*sortName)(const void*, const void*) = &compareByName;
  int (*sortAge)(const void*, const void*) = &compareByAge;
  int (*sortRoll)(const void*, const void*) = &compareByRoll;

  printArray(s, 4);
  printf("\n");

  printf("Sorting By Name : \n");
  quickSort(s, 0, 3, sortName);
  printArray(s, 4);
  printf("\n");

  printf("Sorting By Age : \n");
  quickSort(s, 0, 3, sortAge);
  printArray(s, 4);
  printf("\n");

  printf("Sorting By Roll No : \n");
  quickSort(s, 0, 3, sortRoll);
  printArray(s, 4);
  printf("\n");

}
