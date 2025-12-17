#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		long long int a,b,c;
		scanf("%lld %lld %lld",&a,&b,&c);
		
		long long int e = a*b/100;
		if(e>c) printf("Case #%d: %lld\n",i,c);
		else printf("Case #%d: %lld\n",i,e);
	}
	
	return 0;
}
