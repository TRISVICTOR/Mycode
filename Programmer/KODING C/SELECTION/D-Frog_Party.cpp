#include<stdio.h>

int main(){
	
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++){
		long long int a,b;
		scanf("%lld %lld",&a,&b);
		long long int c=a*b;
		if(c%2==0) printf("Case #%d: Party time!\n",i);
		else printf("Case #%d: Need more frogs\n",i);
	
	}
	
	return 0;
}
