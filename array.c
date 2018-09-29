#include<stdio.h>
#include<stdlib.h>
void calc(int f,int s,int *arr){
	if(*(arr+f)==-1 || *(arr+f+1)){
		int x=1,temp;
		if(f%2==0){
			while(s) {
				temp = arr[s]+arr[s+x];
				arr[s]=temp;
				arr[s+x]=temp;
				x+=2;
				s--;
			}
			
		}else{
			while((f/2)+1) {
				temp = arr[s-x]+arr[s+x];
				arr[s+x]=temp;
				arr[s-x]=temp;
				x+=1;
				f--;
			}
		} 
	}
	
	else {
		calc(f+2,s+1,arr);
	}
}

int main(){
	int arr[6] = {1,2,3,4,5,6};
	int arr1[5] = {1,2,3,4,5};
	int f=0,s=0;
	calc(f,s,arr);
	calc(f,s,arr1);
	while()
	return 0;
}

