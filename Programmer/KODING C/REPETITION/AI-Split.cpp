#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=1;i<=tc;i++){
		int p;
		scanf("%d",&p);getchar();
		
		int a[100001];
		int total=0;
		
		for(int j=0;j<p;j++){
			scanf("%d",&a[j]);getchar();
			total+=a[j];
		}
		
		if(total%2!=0){
			printf("Case #%d: No\n",i);
			continue;
		}
		
		int b=0;
		for(int j=0;j<p;j++){
			b+=a[j];
			if(b==total/2){
				printf("Case #%d: Yes\n",i);
				break;
			}
			if(j==p-1){
				printf("Case #%d: No\n",i);
			}
		}
		
	}
	
	return 0;
}
