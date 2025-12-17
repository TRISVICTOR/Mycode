#include<stdio.h>
#include<string.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		char arr[1001];
		scanf("%s",&arr);
		
		printf("Case %d: ",i);
		
		for(int j=0;j<strlen(arr);j++){
			printf("%d",arr[j]);
			if(j!=strlen(arr)-1){
				printf("-");
			}
		}
		
		printf("\n");
	}
	
	return 0;
}
