#include<stdio.h>

int cou=0;

long long int f(long long int n){
	if(n==0){
		return 1;
	}
	if(n==1){
		return 2;
	}
	if(n%3==0){
		cou++;
	}
	if(n%5==0){
		return n*2;
	}
	
	return f(n-1)+n+f(n-2)+n-2;
}

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		cou = 0;
		long long int n;
		scanf("%lld", &n);
		long long int res = f(n);
		printf("Case #%d: %lld %d",i+1, res, cou);
		puts("");
	}
	
	return 0 ;
}
