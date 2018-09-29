#include <stdio.h>
#include <stdlib.h>

int comp(const void* a, const void* b) {
  return *(int *)a - *(int *)b;
}

void binarySearch(int* arr, int start, int end, int num, int sum, int index) {
  if(start >= end) return;

  if((arr[start] + arr[end]) == sum) {
    if(start != index && end != index) printf("%d %d %d\n", num, arr[start], arr[end]);
  }

  if((arr[start] + arr[end]) <= sum) binarySearch(arr, start + 1, end, num, sum, index);
  else binarySearch(arr, start, end - 1, num, sum, index);   

}

int main() {
  int arr[9] = {1, 3, 6, 2, 5, 4, 3, 2, 4};

  qsort(arr, 9, sizeof(int), comp);

  int sum = 7, temp = 7;

  for(int i = 0; i < 9; i++) {
    temp = sum - arr[i];
    if((i + 1) < 9 && arr[i] == arr[i + 1]) continue;
    binarySearch(arr, i + 1, 8, arr[i], temp, i);
  }

}

