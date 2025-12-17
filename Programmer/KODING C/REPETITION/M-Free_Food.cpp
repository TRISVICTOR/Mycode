#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		long long int a,b;
		scanf("%lld %lld",&a,&b);
		long long int c=0;
		long long int d;

		for(int j=0;j<a;j++){
			scanf("%lld",&d);
			c+=d;
		}
		if(b<c){
			printf("Case #%d: Wash dishes\n",i);
		}
		else{
			printf("Case #%d: No worries\n",i);
		}
	}
	
	return 0;
}
