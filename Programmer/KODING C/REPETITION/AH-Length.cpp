#include <stdio.h>

int main() {
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		long long int n;
		scanf("%lld",&n);
			
		long long int hasil = 0;
		
		do{
			n/=10;
			hasil++;
		}
		while(n!=0);
		
		printf("Case #%d: %lld\n",i,hasil);
	}
	
    return 0;
}
