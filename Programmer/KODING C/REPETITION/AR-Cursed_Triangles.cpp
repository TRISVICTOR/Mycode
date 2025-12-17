#include<stdio.h>

int main(){
	
	int tc,a;
	scanf("%d %d",&tc,&a);
	
	for(int k=0;k<tc;k++){
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				if(j>=a-i-1){
					printf("*");
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
		}
		
	}
	
	return 0;
}
