#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int jumlah_murid;
		scanf("%d",&jumlah_murid);
		
		int banyak=0;
		int tinggi = 0;
		int a[jumlah_murid];
		
		for(int j=0;j<jumlah_murid;j++){
			scanf("%d",&a[j]);
			if(a[j]>tinggi){
				tinggi=a[j];
			}
		}
		
		for(int j=0;j<jumlah_murid;j++){
			if(a[j]==tinggi){
				banyak++;
			}
		}
		
		printf("Case #%d: %d\n",i,banyak);
	}
	
	return 0;
}
