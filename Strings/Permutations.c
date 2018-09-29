#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* x, char* y) {
  char t = *x;
  *x = *y;
  *y = t;
}

void permutate(char* str, int l, int r) {
  if(l == r) {
    printf("%s\n", str);
  }
  for(int x = l; x <= r; x++) {
    swap(&str[l], &str[x]);
    permutate(str, l + 1, r);
    swap(&str[l], &str[x]);
  }
}

int main() {
  char* str = (char *)malloc(sizeof(char) * 5);
  int size = 0;
  int len = strlen(str);
  if(len <= 2) {
    size = len;
  } else {
    if(len == 3) size = 6;
    if(len == 4) size = 24;
    if(len == 5) size = 120;
  }
  char ** res = (char **)malloc(sizeof(char *) * size);
  for(int i = 0; i < size; i++)
  strcpy(str, "abced");
  permutate(str, 0, 4);
}
