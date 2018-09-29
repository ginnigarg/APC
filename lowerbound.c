#include<stdio.h>

int lbound(int *arr,int num){
	int l=0;
	int r=sizeof(arr)/sizeof(int);
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(arr[i]>=num){
			r=mid;
		}else{
			l=mid+1;
		}

	}
	return r;
}

int ubound(int *arr,int num){
	int l=0;
	int r=sizeof(arr)/sizeof(int);
	int mid;
	while(l<r){
		mid = (l+r)/2;
		if(arr[i]>num){
			r=mid;
		}else {
			l=mid+1;
		}
	}
	return r;
}

int main(){
	int arr[] = {1,2,2,3,3,3,5,6,6,6,7,7,7};
	printf("%d\n",lbound())
}
