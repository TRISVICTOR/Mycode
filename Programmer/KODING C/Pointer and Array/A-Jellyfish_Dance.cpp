#include<stdio.h>

int main(){
	
	int a;
	scanf("%d",&a);
	
	int arr[a];
	
	for(int i=0;i<a;i++){
		scanf("%d",&arr[i]);
	}
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int b,c;
		scanf("%d %d",&b,&c);
		int hasil=0;
		
		for(int j=b;j<=c;j++){
			hasil+=arr[j-1];
		}
		printf("Case #%d: %d\n",i,hasil);
	}
	
	return 0;
}
