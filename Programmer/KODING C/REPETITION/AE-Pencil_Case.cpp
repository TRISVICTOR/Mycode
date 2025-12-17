#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		int R,H;
		scanf("%d %d",&R,&H);
		double c=(double)2*3.14*R*(R+H);
		printf("Case #%d: %.2lf\n",i+1,c);
	}
	
	return 0;
}
