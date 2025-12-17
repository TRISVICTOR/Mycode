#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	int arr1[tc];
	int arr2[tc];
	
	for(int i=0;i<tc;i++){
		scanf("%d",&arr1[i]);
	}
	
	int hasil[tc];
	
	for(int i=0;i<tc;i++){
		scanf("%d",&arr2[i]);
	}
	
	for(int i=0;i<tc;i++){
		hasil[arr1[i]] = arr2[i];
	}
	
	for(int i=0;i<tc;i++){
		printf("%d",hasil[i]);
		if(i<tc-1){
			printf(" ");
		}
	}
	printf("\n");
	
	return 0;
}
