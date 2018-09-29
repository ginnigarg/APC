#include<stdio.h>
#include<stdlib.h>
void add(int *arr,int ele,int i,int &size){
	*(arr+i) = ele;
	if(i>) 
}
int main() {
	int size=10,i=0;
	int *arr = (int *)malloc(sizeof(int)*10);
	add(arr,1,i,size);
	return 0;
}

