#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	int a[tc];
	int b=0;
	
	for(int i=0;i<tc;i++){
		scanf("%d",&a[i]);
	}
	
	for(int j=0;j<tc;j++){
		b+=a[j];
		b%=40;
		if(b==30){
			b=10;
		}
		else if(b==12){
			b=28;
		}
		else if(b==35){
			b=7;
		}
	}
	
	printf("%d\n",b);
	
	return 0;
}
