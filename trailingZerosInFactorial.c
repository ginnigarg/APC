#include<stdio.h>
#include<math.h>
int trail(int x){
	int ans=0,i=1;
	while(pow(5,i)<x){
		ans += x/(pow(5,i));
		i++;
	}
	return ans;
}
int main(){
	printf("%d",trail(100));
}
