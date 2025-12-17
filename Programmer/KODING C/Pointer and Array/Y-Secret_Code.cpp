#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int c;
		char arr[1005];
		scanf("%d %s",&c,&arr);getchar();
		
		for(int j=0;j<c;j++){
			int a,b;
			scanf("%d %d",&a,&b);
			a--;
			b--;
			for(int k=a;k<b;k++){
				char d=arr[k];
				arr[k]=arr[b];
				arr[b]=d;
				b--;
			}
		}
		
		printf("Case #%d: %s\n",i,arr);
		
	}
	
	return 0;
}
