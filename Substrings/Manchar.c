#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b) {
    return (a>b)?b:a;
}

char* longestPalindrome(char* A) {
    int len = (2 * strlen(A)) + 1, i = 0, j = 0;
 
    char* str = (char *)malloc(sizeof(char) * len);
    while(i < len) {
      str[i++] = '$';
      if(i < len) str[i++] = A[j++];
    }

    int start = 0, end = 0, newCenter;

    int *arr = (int *) malloc(sizeof(int) * len);

    for(i = 0; i < len; i++) {
      arr[i] = 1;
    }
    i = 0;

    while(i < len - 1) {

        while(start > 0 && end < len && str[start - 1] == str[end + 1]) {
            start--;
            end++;
        }
        printf("%d %d\n", start, end);
        // for(j = start; j <= end; j++) {
        //     printf("str[j] : %c\n", str[j]);
        // }
        //printf("\n");
        arr[i] = end - start + 1; 
        newCenter = end  + 1;
        for(j = i + 1; i <= end; i++){
            arr[j] = min(arr[i - (j - i)], (2 * (end - j) + 1));
            printf("j : %d\tarr[j] : %d\n", j, arr[j]);
            if((j + arr[i - (j - i)]/2) == end) {
                newCenter = j;
                break;
            }
        }
        i = newCenter;
        printf("newCenter : %d\n", i);
        start = i - (arr[i]/2);
        end = i + (arr[i]/2);
    }
    arr[len - 1] = 1;
    //printf("%d %d %d %d\n", i, arr[i], start, end);
    for(j = 0; j < len; j++) {
        printf("%d ", arr[j]);
    }
    int max = 0;
    for(i = 1; i < len; i++) {
        if(arr[i] > arr[max]) {
            max = i;
        }
    }
    int val = arr[max];
    start = max - (arr[max]/2);
    end = max + (arr[max]/2);
    char* ans = (char *)malloc(sizeof(char) * val);
    j = 0;
    printf("Max Value : %d at %d index with start : %d and end : %d\n", val, max, start, end);
    for(i = start; i <= end ; i++) {
        if(str[i] != '$') ans[j++] = str[i];
    }
    printf("%s\n", ans);
    return ans;
}

int main() {

  char* str = longestPalindrome("abb");
  printf("%s\n", str);


}
