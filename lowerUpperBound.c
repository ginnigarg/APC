#include <stdio.h>
#include <stdlib.h>

int lowerBound(int* arr, int num, int left, int right) {
    if(left >= right) {
        return left;
    }
    int mid = (left + right) / 2;
    if(arr[mid] >= num) {
        return lowerBound(arr, num, left, mid);
    }
    return lowerBound(arr, num, mid + 1, right);
}

int upperBound(int* arr, int num, int left, int right) {
    if(left >= right) {
        return left;
    }
    int mid = (left + right) / 2;
    if(arr[mid] > num) {
        return upperBound(arr, num, left, mid);
    }
    return upperBound(arr, num, mid + 1, right);
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int *) malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int num, q;
        scanf("%d %d", &num, &q);
        if(q == 0) {
            printf("%d\n", lowerBound(arr, num, 0, n - 1));
        } else {
            printf("%d\n", upperBound(arr, num, 0, n - 1));
        }
    }
    return 0;
}
