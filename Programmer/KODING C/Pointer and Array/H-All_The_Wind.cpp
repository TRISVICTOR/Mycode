#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int k=1;k<=tc;k++){
		int nilai;
		scanf("%d",&nilai);
		
		long long int matrix[nilai][nilai];
		
		for(int i=0;i<nilai;i++){
			for(int j=0;j<nilai;j++){
				scanf("%lld",&matrix[i][j]);
			}
		}
		
		long long int hasil[nilai];
		for(int i=0;i<nilai;i++){
			hasil[i] = 0;
		}
		
		
		for(int i=0;i<nilai;i++){
			for(int j=0; j<nilai;j++){
				hasil[j] += matrix[i][j];
			}
		}
		
		printf("Case #%d:",k);
		
		for(int i=0;i<nilai;i++){
			printf(" %lld",hasil[i]);
		}
		
		printf("\n");
		
	}
	
	return 0;
}
