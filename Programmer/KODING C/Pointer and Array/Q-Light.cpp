#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d", &tc); getchar();
	
	for(int i = 0; i < tc; i++){
		int n, m, q;
		scanf("%d %d %d", &n, &m, &q); getchar();
		
		int pattern[n][m];
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				scanf("%d", &pattern[j][k]); getchar();
			}
		}
		
		int light[m];
		for(int j = 0; j < m; j++){
			light[j] = 0;
		}
		
		for(int j = 0; j < q; j++){
			int fren;
			scanf("%d", &fren); getchar();
			fren--;
			
			for(int k = 0; k < m; k++){
				if(pattern[fren][k] == 1){
					light[k] = 1 - light[k];
				}
			}
		}
		
		printf("Case #%d:\n", i + 1);
		for(int j = 0; j < m; j++){
			if(light[j] == 1){
				printf("YES\n");
			}else{
				printf("NO\n");
			}
		}
	}
	
	
	return 0;
}
