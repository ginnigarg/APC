#include<stdio.h>

int binarySearch(int *arr,int start,int end,int num){
	if(start<end){
		int mid = (start+end)/2;
		if(arr[mid]==num) return mid;
		if(arr[mid]>num) return binarySearch(arr,start,mid-1,num);
		if(arr[mid]<num) return binarySearch(arr,mid+1,end,num);
	}
	return -1;
}

int main(){
	int arr[] = {1,2,3,4,5,5,6,7,8,9};
	printf("%d ",binarySearch(arr,0,10,1));
	printf("%d ",binarySearch(arr,0,10,9));
        printf("%d ",binarySearch(arr,0,10,5));
        printf("%d ",binarySearch(arr,0,10,10));
        printf("%d ",binarySearch(arr,0,10,0));
	return 0;
}
