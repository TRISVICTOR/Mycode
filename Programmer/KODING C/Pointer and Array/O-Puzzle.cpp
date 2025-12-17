#include <stdio.h>

int main(){
	
	int n;
	scanf("%d",&n);
	
	int arr[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(arr[i][j]==arr[i][k]){
					printf("Nay\n");
					return 0;
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=i+1;k<n;k++){
				if(arr[i][j]==arr[k][j]){
					printf("Nay\n");
					return 0;
				}
			}
		}
	}
	
	printf("Yay\n");
	
	return 0;
}
