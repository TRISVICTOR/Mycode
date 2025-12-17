#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int jumlah;
		scanf("%d",&jumlah);
		
		int a[jumlah];
		int b[jumlah];
		
		for(int j=0;j<jumlah;j++){
			scanf("%d",&a[j]);
		}
		for(int j=0;j<jumlah;j++){
			scanf("%d",&b[j]);
		}
		
		printf("Case #%d:",i);
		int hasil=0;
		
		for(int j=0;j<jumlah;j++){
			hasil=a[j]-b[j];
			printf(" %d",hasil);
			hasil=0;
		}
		printf("\n");
	}
	
	return 0;
}
