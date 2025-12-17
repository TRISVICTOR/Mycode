#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	long long int a;
	long long int hasil = 0;
	
	for(int i=0;i<tc;i++){
		scanf("%lld",&a);
		if(a>0){
			hasil+=a;
		}
	}
	
	printf("%lld\n",hasil);
	
	return 0;
}
