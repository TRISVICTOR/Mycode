#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i = 1;i<=tc;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		if(a>b) printf("Case #%d: Go-Jo\n",i);
		else printf("Case #%d: Bi-Pay\n",i);
	}
	return 0;
}
