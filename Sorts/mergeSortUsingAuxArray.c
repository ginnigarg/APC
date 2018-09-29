#include <stdio.h>
#include <stdlib.h>

void merge(int* a, int start, int mid, int end, int* aux) {
  int k;
  int i = start;
  int j = mid + 1;

  for(k = start; k <= end; k++) {
    if(i > mid) aux[k] = a[j++];
    else if(j > end) aux[k] = a[i++];
    else if(a[i] < a[j]) aux[k] = a[i++];
    else aux[k] = a[j++];
  }

  for(k = start; k <= end; k++) {
    a[k] = aux[k];
  }
}

void mergeSort(int* arr, int start, int end, int* aux) {
    if(end <= start) return;

    int mid = (start + end) / 2;

    mergeSort(arr, start, mid, aux);
    mergeSort(arr, mid + 1, end, aux);
    merge(arr, start, mid, end, aux);
}

int main() {
  int size = 5, i;

  scanf("%d", &size);

  int* arr = (int *) malloc (sizeof(int) * size);
  int* aux = (int *) malloc (sizeof(int) * size);

  for(i = 0; i < size; i++){
    scanf("%d", &arr[i]);
  }

  mergeSort(arr, 0, size-1, aux);

  for(int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  } 
}
