#include<stdio.h>
#include<math.h>
int invert(int num,int n,int p);
int main(){
	int num,n,p;
	scanf("%d %d %d",&num,&n,&p);
	printf("%d",invert(num,n,p));
	return 0;
}

int invert(int num,int n,int p) {
	int x = ~(-1<<n)<<p;
	return (num^x);
}

