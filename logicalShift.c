#include<stdio.h>
int shift(int x,int n);
int main(){
	int x,n;
	scanf("%d %d",&x,&n);
	printf("%d\n",shift(x,n));
	return 0;
}
int shift(int x,int n) {
	return (x>>n)&~(-1<31);
}
