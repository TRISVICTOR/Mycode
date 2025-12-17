#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	char a[101]={"abcdefghijklmnopqrstuvwxyz"};
	
	for(int i=1;i<=tc;i++){
		int b;
		scanf("%d",&b);getchar();
		
		printf("Case #%d: ",i);
		for(int j=0;j<b;j++){
			printf("%c",a[j]);
		}
		printf("\n");
	}
	
	return 0;
}
