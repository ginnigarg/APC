#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printRandoms(int lower, int upper,int count,FILE * fptr){
	for (int i = 0; i < count; i++) {
		int num = (rand() % (upper - lower + 1)) + lower;
		fprintf(fptr,"%d\n",num);
	}
}

void readRandoms(FILE *fptr,int *arr,int size){
	int num;
	for(int i=0;i<size;i++){
		fscanf(fptr,"%d",&num);
		arr[i]=num;
	}
}

void printArray(FILE *fptr,int *arr,int size){
	for(int i=0;i<size;i++){
		fprintf(fptr,"%d\n",arr[i]);
	}
}

void merge(int *arr,int left,int mid,int right,int *aux){
	int i,j,k;
	


}

void mergesort(int *arr,int left,int right,int *aux){
	if(left<right){
		int mid = (left+right)/2;
		mergesort(arr,left,mid,aux);
		mergesort(arr,mid+1,right,aux);
		merge(arr,left,right,mid,aux);
	}
}
int main(){
	FILE *fInput1 = (FILE *)fopen("input16000.txt","r");
	FILE *fOutput1 = (FILE *)fopen("output16000.txt","rw+");
	FILE *fInput2 = (FILE *)fopen("input32000.txt","r");
	FILE *fOutput2 = (FILE *)fopen("output32000.txt","rw+");
	int arr1[16000],arr2[32000];
	//srand(time(0));
	//printRandoms(0,20000,16000,fInput1);
	//printRandoms(0,40000,32000,fInput2);
	readRandoms(fInput1,arr1,16000);
	readRandoms(fInput2,arr2,32000);
	clock_t start,end;
	start = clock();
	bubblesort(arr1,16000);
	end = clock();
	printf("16000 : %lf\n",(double)end-start);
	start = clock();
	bubblesort(arr2,32000);
	end = clock();
	printf("32000 : %lf\n",(double)end-start);
	printArray(fOutput1,arr1,16000);
	printArray(fOutput2,arr2,32000);
	return 0;
}
