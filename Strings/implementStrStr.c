#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*int zvalue(char* A, int i) {
  int ans = 0;
  while(A[i] == A[ans] && A[i] != '\0') {
    ans++;
    i++;
  }
  return ans;
}*/

int implement(char* M, char* P) {
  int len1 = strlen(M), len2 = strlen(P), i, left, right;
  int len = len1 + len2 + 1;
  char* str = malloc(sizeof(char) * len);
  strcat(str, P);
  strcat(str, "$");
  strcat(str, M);
//  printf("%s\n", str);
  int* z = malloc(sizeof(int) * len);
  z[0] = 0;
  left = 0;
  right = 0;
  for(i = 1; i < len; i++) {
    //z[i] = zvalue(str, i);
    if(i > right) {
      left = i;
      right = i;
      while(right < len && (str[right] == str[left - right + 1])) {
        right++;
      }
      z[i] = right - left;
      right--;
    } else {
      if(z[i - left] < right - i + 1) {
                                  



      }



    }
  }
/*  for(i = 0; i < len; i++) {
    printf("%d ", z[i]);
  }*/
  return 1;
}

int main() {
  char* A = "hello world hello";
  char* B = "world";
  implement(A, B);
  return 0;

}

