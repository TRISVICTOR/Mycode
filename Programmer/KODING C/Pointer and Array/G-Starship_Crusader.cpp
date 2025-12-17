#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int a;
		scanf("%d",&a);
		
		int b[a];
		int c[a];
		
		for(int j=0;j<a;j++){
			scanf("%d",&b[j]);
		}
		for(int j=0;j<a;j++){
			scanf("%d",&c[j]);
		}
		
		int hasil=0;
		
		for(int j=0;j<a;j++){
			if(b[j]<c[j]){
				hasil++;
			}
		}
		
		printf("Case #%d: %d\n",i,hasil);
	}
	
	return 0;
}
