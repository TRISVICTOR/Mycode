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
	
}


int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=0;i<tc;i++){
		char arr[1001];
		scanf("%s",&arr);getchar();
		
		int a=strlen(arr);
		
		char arr2[1001];
		for(int j=0;j<a;j++){
			arr2[j]=arr[j];
		}
		
		printf("Case #%d: ",i+1);
		balik(arr);
		
		int cek=0;
		
		for(int j=0;j<a;j++){
			if(arr[j]==arr2[j]){
				cek++;
			}
		}
		if(cek==a){
			printf("yes\n");
		}
		else{
			printf("no\n");
		}
	}
	
	return 0;
}
