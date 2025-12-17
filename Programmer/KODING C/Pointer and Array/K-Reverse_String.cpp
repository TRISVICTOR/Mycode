#include<stdio.h>
#include<string.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=1;i<=tc;i++){
		char arr[1001];
		scanf("%s",&arr);getchar();
		
		char b[1001];
		int panjang=strlen(arr);
		
		for(int j=0;j<panjang;j++){
			b[j]=arr[panjang-j-1];
		}
		
		printf("Case #%d : ",i);
		
		for(int j=0;j<panjang;j++){
			printf("%c",b[j]);
		}
		printf("\n");
	}
	
	return 0;
}
