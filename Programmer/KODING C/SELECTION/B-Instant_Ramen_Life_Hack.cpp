#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i = 1;i<=tc;i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		if(b+c<a) printf("Case #%d: no\n",i);
		else printf("Case #%d: yes\n",i);
	}
	
	return 0;
}
