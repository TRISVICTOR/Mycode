#include <stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int k=1;k<=tc;k++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		int d[a];
		int max = c;
		
		for(int i=0;i<a;i++){
			scanf("%d",&d[i]);
			if(d[i]<=b && d[i]>max){
				max = d[i];
			}
		}
		printf("Case #%d: %d\n",k, max);
	}
	return 0;
}
