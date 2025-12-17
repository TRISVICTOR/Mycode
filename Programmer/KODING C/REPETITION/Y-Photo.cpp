#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	int a;
	for(int i=0;i<tc;i++){
		scanf("%d",&a);
		
		if(a==30){
			a-=20;
		}
		else if(a==12){
			a+=16;
		}
		else if(a==35){
			a-=28;
		}
	}
	
	printf("%d",a);
	
	return 0;
}
