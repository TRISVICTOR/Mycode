#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d", &tc); getchar();
	
	for(int i = 0; i < tc; i++){
		int n;
		scanf("%d", &n);
		
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				if(j == 0 || j == n - 1 || k == 0 || k == n -1 || j == k || k == n - j - 1){
					printf("*");
				}else{
					printf(" ");
				}
			}
			printf("\n");
		}
		printf("\n");
		
	}
	
	
	return 0;
}
