#include<stdio.h>
int fibo(int num) {
	if(num == 0 || num == 1) return num;
	return fibo(num - 1) + fibo(num - 2);
}

int main() {
	int num;
	scanf("%d", &num);
	printf("%d\n", fibo(num));
	return 0;
}
