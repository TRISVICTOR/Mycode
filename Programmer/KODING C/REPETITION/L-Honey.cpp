#include <stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int k=1;k<=tc;k++){
		long long int a,b;
		scanf("%lld %lld",&a,&b);
		
		long long int hasil = a;
		
		while(a>=b){
			a=a-b;
			hasil++;
			a++;
		}
		
		printf("Case #%d: %lld\n",k,hasil);
	}
	
	return 0;
}
