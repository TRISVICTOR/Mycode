#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		long long int a,b;
		scanf("%lld %lld",&a,&b);
		
		long long int c = b/2;
		long long int d = (a/2)-(b/2);
		long long int hasil;
		
		if(c<d){
			hasil = c;
		}
		else{
			hasil = d;
		}
		printf("Case #%d: %lld\n",i,hasil);
	}
	
	return 0;
}
