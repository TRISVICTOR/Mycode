#include<stdio.h>

int main(){
	
	int a;
	scanf("%d",&a);
	
	int b[a];
	
	for(int i=0;i<a;i++){
		scanf("%d",&b[i]);
	}
	
	int hasil;
	
	for(int i=1;i<=a;i++){
		if(b[i]==1){
			printf("%d ",hasil);
			hasil=1;
		}
		else{
			hasil++;
		}
	}
	
	printf("%d\n",hasil);
	
	return 0;
}
