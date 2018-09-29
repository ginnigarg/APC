#include<stdio.h>
int cond(int x,int y,int z){
int tmp = (((x) | (~x +1))>>31);
return (tmp & y) + (~tmp &z);
} 
int main(){
	printf("%d %d\n",cond(1,4,5),cond(0,4,5));
	return 0;
}

