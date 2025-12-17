#include <stdio.h>

int main(){
	
    int tc;
    scanf("%d",&tc);
   	long long int a;
    
    for(int i=1;i<=tc;i++){
    	scanf("%lld",&a);
    	long long int hasil=1;
    	printf("Case %d:",i);
    	for(int j=0;j<a;j++){
    		if(j>0){
    			hasil+=j;
			}
			printf(" %lld",hasil);
		}
		printf("\n");
	}

    return 0;
}
