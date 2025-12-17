#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		long long int t;
		scanf("%lld",&t);
		getchar();
		int a[t];
		
		long long int b;
		long long int selisih=10000000000;
		
		for(int j=0;j<t;j++){
			scanf("%d", &a[j]);
		}
		
		for(int k=0;k<t-1;k++){
			b = a[k+1]-a[k];
			if(b < 0){
				b = -b;
			}
			if(b < selisih){
				selisih=b;
			}
		}
		
		printf("Case #%d: %lld\n",i,selisih);
	}
	
	return 0;
}
