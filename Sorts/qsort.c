#include<stdio.h>
#include<stdlib.h>
int comp(const void *a,const void *b){
	return (*(int *)b - *(int *)a);
}
int main(){
	int arr[10] = {1,3,5,7,9,2,4,6,8,0};
	qsort(arr,10,sizeof(int),comp);
	for(int i=0;i<10;i++){
		printf("%d ",arr[i]);
	}
}
