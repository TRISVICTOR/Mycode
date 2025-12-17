#include<stdio.h>

int main(){
	
	int x,y,k;
	scanf("%d %d %d",&x,&y,&k);
	
	if(x>k || y<k){
		printf("-1\n");
		return 0;
	}
	
	if((k - x) == (y - k)) printf("%d\n",k-x);
	else printf("-1\n");
	
	return 0;
}
