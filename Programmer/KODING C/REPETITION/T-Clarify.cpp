#include<stdio.h>

int main(){
	
	long long int tc;
	scanf("%lld",&tc);
	long long int hasil=0;
	
	for(int i=0;i<tc;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(c<b){
			hasil++;
		}
	}
	
	printf("%lld\n",hasil);
	
	return 0;
}
