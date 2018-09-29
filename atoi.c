#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int Atoi(char* str) {
  int i = 0;
  long long int ans = 0;
  char sign;
  if(str[0] == '-' || str[0] == '+') {
    i++;
    sign = str[0];
  }
  while(str[i] != '\0' && str[i] != ' ') {
    ans = (ans * 10) + (str[i] - 48);
    i++;
  }
  if(sign == '-') {
    ans *= -1;
  }
  if(ans > INT_MAX) {
    return INT_MAX;
  }else if(ans < INT_MIN){
    return INT_MIN;
  }else {
    return ans;
  }
}

int main() {
  char* str = "5121478262";
  printf("%d\n", Atoi(str));
}
