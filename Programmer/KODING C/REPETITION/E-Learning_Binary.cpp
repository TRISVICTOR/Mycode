#include <stdio.h>

int main(){
	
    int tc;
    scanf("%d",&tc);
    
    for(int i=0;i<tc;i++){
    	long long int a;
    	int b;
    	scanf("%lld %d",&a,&b);
    	int hasil = (a>>b) & 1;
    	printf("%d\n",hasil);
	}
	
    return 0;
}
