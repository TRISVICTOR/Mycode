#include <stdio.h>

int main() {
    
    int tc;
    scanf("%d",&tc);
    
    for(int i=1;i<=tc;i++){
    	int a;
    	scanf("%d",&a);
    	long long int hasil=0;
    	
    	for(int j=0;j<a;j++){
    		long long int b;
    		scanf("%lld",&b);
    		hasil+=b;
		}
		printf("Case #%d: %lld\n",i,hasil);
	}
    
    return 0;
}
