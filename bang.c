#include<stdio.h>
int bang(int n);
int main(){
	int num;
	scanf("%d",&num);
	printf("%d",bang(num));
	return 0;
}
int bang(int n) {
	return (n&(~n)&n);
}
