#include<stdio.h>
#include<stdlib.h>
int * merge(int *a,int *b,int x,int y,int *l){
	int i=0,j=0,k=0;
	int * arr = (int *)malloc(sizeof(int)*(x+y));
	while(i<x && j<y){
		if(a[i]>b[j]){
			arr[k]=b[j];
			j++;
			k++;
		}else {
			arr[k]=a[i];
			i++;
			k++;
		}
	}
	while(i<x){
		arr[k]=a[i];
		i++;
		k++;
	}
	while(j<y){
		arr[k]=b[j];
		j++;
		k++;
	}
	*l = x+y;
	return arr;
}

int main(){
	int a[3] = {3,5,6};
	int b[3] = {1,2,4};
	int length;
	int * arr = merge(a,b,3,3,&length);
	for(int i=0;i<length;i++){
		printf("%d ",arr[i]);
	} 
	return 0;
}
