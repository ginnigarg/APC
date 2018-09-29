#include<stdio.h>
int fab(int num) {
	if(num==0) {
		return 0;
	}
	if(num==1) {
		return 1;
	}
	return fab(num-1)+fab(num-2);
}

int main() {
	int num;
	scanf("%d",&num);	
	printf("%d ",fab(num));
	return 0;
}
