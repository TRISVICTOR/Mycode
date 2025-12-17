#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	int a;
	long long int b;
	
	for(int i=1;i<=tc;i++){
		scanf("%d %lld",&a,&b);
		char c[a+1];
		scanf("%s",&c);
		
		for(int j=0;j<a;j++){
			int d=c[j]-'a';
			int e=(d+b)%26;
			c[j]=e+'a';
		}
		printf("Case #%d: %s\n",i,c);
	}
	
	return 0;
}
