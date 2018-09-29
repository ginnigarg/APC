#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kmp (char* txt, char* pattern) {
  int len1 = strlen(txt), len2 = strlen(pattern);
  int i, j;
  int* arr = (int *)malloc(sizeof(int) * len2);
  i = 0;
  j = 1;
  arr[0] = 0;
  while(j < len2) {
    if(pattern[i] == pattern[j]) {
      //printf("%d : %d\n",j, i);
      arr[j++] = ++i;
    } else {
      if(i == 0) {
        //printf("%d : 0\n",j);
        arr[j] = 0;
        j++;
      } else {
        i = arr[i - 1];
      }
   }
  }
  for(i = 0; i < len2; i++) {
    printf("%d ", arr[i]);
  }
  i = 0;
  j = 0;
  while(i < len1) {
    if(txt[i] == pattern[j]) {
      i++;
      j++;
    }
    if(j == len2) {
      printf("Pattern Found at %d\n", i - j);
      j = arr[j - 1];
    } else {
      if(i < len1 && txt[i] != pattern[j]) {
        if(j == 0) {
          i++;
        } else {
          j = arr[j  - 1];
        }
      }
    }
  }
}

int main() {
  char* txt = "abcabcabc";
  char* pattern = "aaabaaabxyzaaabaaabd";

  kmp(txt, pattern);
  return 0;
}
