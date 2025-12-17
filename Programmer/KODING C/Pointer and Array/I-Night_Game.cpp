#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int a;
		scanf("%d",&a);
		
		int arr[a];
		int b[a];
		
		for(int j=0;j<a;j++){
			scanf("%d",&arr[j]);
		}
		
		printf("Case #%d:",i);
		
		for(int j=0;j<a;j++){
			b[j]=arr[a-1-j];
		}
		
		for(int j=0;j<a;j++){
			printf(" %d",b[j]);
		}
		printf("\n");
	}
	
	return 0;
}
