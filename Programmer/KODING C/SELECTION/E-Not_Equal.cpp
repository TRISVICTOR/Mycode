#include<stdio.h>

int main(){
	
	long long int a,b,c,d;
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	long long int e=a*b;
	long long int f=c+d;
	if(e>f) printf("True\n");
	else printf("False\n");
	
	return 0;
}
