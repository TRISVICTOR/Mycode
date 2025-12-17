#include <stdio.h>
int main(){
	
	int tc;
	scanf("%d", &tc);getchar();
	
	for(int i=1;i<=tc;i++){
		long long int n;
		scanf("%lld", &n);getchar();
		
		long long int a[n];
		for (int j = 0; j < n; j++){
			scanf("%lld", &a[j]);
		}
		
		long long int b= -1000000;
		long long int c= -1000000;
		for (int j = 0; j < n; j++){
			if (a[j] > b){
				c=b;
				b=a[j];
			}else if(a[j] > c){
				c=a[j];
			}
			
		}
		
		printf("Case #%d: %lld\n",i,c + b);
	}
	return 0;
}
