#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	long long int hasil=0;
	int a;
	
	for(int i=0;i<tc;i++){
		scanf("%d",&a);getchar();
		hasil+=a;
	}
	printf("%lld\n",hasil);
	
	return 0;
}
