#include<stdio.h>

int main(){
	
	int nilai;
	scanf("%d",&nilai);
	
	int angka[nilai];
	
	for(int i=0;i<nilai;i++){
		scanf("%d",&angka[i]);
	}
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		
		angka[a-1]=b;
		
		printf("Case #%d:",i);
		
		for(int j=0;j<nilai;j++){
			printf(" %d",angka[j]);
		}
		printf("\n");
	}
	
	return 0;
}
