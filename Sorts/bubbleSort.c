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
	/*for(int i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");*/
}

void printArray(FILE *fptr,int *arr,int size){
	for(int i=0;i<size;i++){
		fprintf(fptr,"%d\n",arr[i]);
	}
}

void bubblesort(int *arr,int size){
	clock_t start,end;
	start = clock();
	for(int i=0;i<size-1;i++){
		for(int j=0;j<size-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
		//printf("%")gettimeofday();
	} 
	end = clock();
	printf("%d : %lf\n",size,(double)(end-start));
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
	bubblesort(arr1,16000);
	bubblesort(arr2,32000);
	printArray(fOutput1,arr1,16000);
	printArray(fOutput2,arr2,32000);
	return 0;
}
