#include <stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int k=1;k<=tc;k++){
		int a;
		scanf("%d",&a);
		
		printf("Case #%d:\n",k);
		
		for(int i=1;i<=a;i++){
			for(int j=1;j<=a;j++){
				if(j>=a-i+1){
					if((i+j)%2==0){
						printf("*");
					}
					else{
						printf("#");
					}
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	
	return 0;
}
