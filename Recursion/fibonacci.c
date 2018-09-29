#include<stdio.h>
void fibo(int num,int first,int second){
	if(num == 0) return;
	printf("%d ",first);
	fibo(--num,second,first+second);
}

int main(){
	int num;
	scanf("%d",&num);
	fibo(num,0,1);
	return 0;




}
