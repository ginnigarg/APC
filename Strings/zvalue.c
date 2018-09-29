#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* createNewString(char* text, char* pattern) {
  int len = strlen(text) + strlen(pattern) + 1, i = 0, j = 0;
  char* str = (char *)malloc(sizeof(char) * len);

  while(pattern[j] != '\0') {
    str[i++] = pattern[j++];
  }

  str[i++] = '$';
  j = 0;

  while(text[j] != '\0') {
    str[i++] = text[j++];
  }

  str[i] = '\0';

  return str;
}

int* ztable(char* str) {
  int len = strlen(str);
  len = strlen(str);
  int* z = (int *)malloc(sizeof(int) * len);
  z[0] = 0; 
  int left = 0, right = 0, i = 1, j, newBegin;
  while(i < len) {
    left = 0;
    right = i; 
    while(str[left] == str[right]) {
      left++;
      right++;
    }
    left = 1;
    z[i] = right - i;
    newBegin = right + 1;
    for(j = i + 1; j <= right;) {
      if((z[left] + j) < right) {
         z[j++] = z[left++];
      } else {
        newBegin = j;
        break;
      }
    }
    i = newBegin;
  }
  return z;
} 

int zvalue(char* text, char* pattern) {
  int len = strlen(text) + strlen(pattern) + 1;
  char * str = createNewString(text, pattern);
  printf("%s\n", str);
  int* z = ztable(str);
  for(int i = 0; i < len; i++) {
    if(z[i] == strlen(pattern)) {
      return i - strlen(pattern) - 1;
    }
  }
  return -1;
}

int main() {
  int ans = zvalue("xyz", "abc");
  printf("%d\n", ans);
  return 0;
}
