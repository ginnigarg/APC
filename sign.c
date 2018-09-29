#include<stdio.h>
int sign(int n);
int main(){
	int num;
	scanf("%d",&num);
	printf("%d\n",sign(num));
	return 0;
}
int sign(int n) {
	return (n>>31)|!(!n);
}
