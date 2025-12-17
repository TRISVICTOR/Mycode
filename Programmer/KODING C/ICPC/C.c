#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d\n",&tc);
	long long int arr[tc];
	
	for(int i = 0;i<tc;i++){
		scanf("%lld",&arr[i]);
	}
	
	for(int i = 0;i<tc;i++){
		printf("%lld",arr[i]);
	}
	
	return 0;
}
