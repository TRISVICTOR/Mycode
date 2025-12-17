#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int k=1;k<=tc;k++){
		int a;
		scanf("%d",&a);
		
		int arr[a][a];
		
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				scanf("%d",&arr[i][j]);
			}
		}
		
		int hasil[a];
		for(int i=0;i<a;i++){
			hasil[i]=0;
		}
		
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				hasil[j]+=arr[i][j];
			}
		}
		
		printf("Case #%d:",k);
		for(int i=0;i<a;i++){
			printf(" %d",hasil[i]);
		}
		printf("\n");
	}
	
	return 0;
}
