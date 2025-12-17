#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	int a,b;
	for(int i=0;i<tc;i++){
		scanf("%d %d",&a,&b);getchar();
		
		printf("Case #%d: ",i+1);
		
		int hasil=0,o=1;
		while(a || b){
			int sum=(a%10)+(b%10);
			sum%=10;
			
			hasil+=sum*o;
			
			a/=10;
			b/=10;
			o*=10;
		}
		printf("%d\n",hasil);
	}
	
	return 0;
}
