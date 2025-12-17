#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		
		int jumlah=0;
		
		int arr[a];
		for(int j=0;j<a;j++){
			scanf("%d",&arr[j]);
		}
		
		for(int j=0;j<a;j++){
			for(int k=0;k<a-1;k++){
				if(arr[k]>arr[k+1]){
					int c=arr[k];
					arr[k]=arr[k+1];
					arr[k+1]=c;
					jumlah+=b;
				}
			}
		}
		
		printf("Case #%d: %d\n",i+1,jumlah);
	}
	
	return 0;
}
