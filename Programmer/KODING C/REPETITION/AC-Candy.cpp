#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d", &tc); getchar();
	
	for(int i = 0; i < tc; i++){
		int n; 
		long long int m;
		int result;
		int a[10001];
		
		scanf("%d %lld", &n, &m); getchar();
		
		for(int j = 0; j < n; j++){
			scanf("%d", &a[j]); getchar();
		}
		
		int min = a[0];
		for(int j = 1; j < n; j++){
			if(a[j] < min){
				min = a[j];
			}
		}
		
		if(min > m){
			result = 0;
		}else{
			result = m / min;
		}

        printf("Case #%d: %d\n", i + 1, result);
	}
	
	return 0;
}
