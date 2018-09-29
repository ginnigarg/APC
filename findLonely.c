#include<stdio.h>
int main(){
	int size,xor;
	printf("Enter the size : ");
	scanf("%d",&size);
	int *arr = (int *)malloc(sizeof(int)*size);
	printf("Enter the elements of array : \n");
	for(int i=0;i<size;i++){
		scanf("%d",(arr+i));
	}
	xor = arr[0]^arr[1];
	for(int i=2;i<size;i++) {
		xor = xor^arr[i];
	}
	printf("%d",xor);
	return 0;
	
}
