#include<stdio.h>
#include<string.h>
#include<string.h>

void balik(char* arr){
	int panjang=strlen(arr);
	
	for(int i=0;i<panjang/2;i++){
		char huruf=arr[i];
		arr[i]=arr[panjang-1-i];
		arr[panjang-1-i]=huruf;
	}
	printf("%s\n",arr);
}


int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=0;i<tc;i++){
		char arr[1001];
		scanf("%[^\n]",&arr);getchar();
		printf("Case #%d: ",i+1);
		balik(arr);
	}
	
	return 0;
}
