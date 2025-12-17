#include<stdio.h>

int main(){

	int tc;
	scanf("%d",&tc);getchar();

	for(int i=0;i<tc;i++){
		long long int x;
		scanf("%lld",&x);getchar();
		x-=1;
		printf("Case #%d: ",i+1);
		if(x==0){
			printf("0\n");
		}
		else if(x==1){
			printf("1\n");
		}
		else{
			long long int a=0,b=1,total;
			for(int j=2;j<=x;j++){
				total=a+b;
				a=b;
				b=total;
			}
			printf("%lld\n",total);
		}
	}

	return 0;
}
