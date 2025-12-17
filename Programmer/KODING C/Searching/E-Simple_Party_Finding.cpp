#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		int n;
		scanf("%d",&n);
		
		int arr[n];
		for(int j=0;j<n;j++){
			scanf("%d",&arr[j]);
		}
		
		int D;
		scanf("%d",&D);
		
		for(int j = 0; j < n - 1; j++){
			for(int k = j + 1; k < n; k++){
				if(arr[j] > arr[k]){
					int temp = arr[j];
					arr[j] = arr[k];
					arr[k] = temp;
				}
			}
		}
		
		int ketemu=0;
		int kiri,kanan;
		
		for(int j=0;j<n;j++){
			if(arr[j]==D){
				ketemu=1;
				if(j==0){
					kiri=arr[0];
					kanan=arr[1];
				}
				else if(j==n-1){
					kiri=arr[n-2];
					kanan=arr[n-1];
				}
				else{
					kiri=arr[j];
					kanan=arr[j+1];
				}
				break;
			}
		}
		if(!ketemu){
			printf("CASE #%d: -1 -1\n", i + 1);
		}else{
			printf("CASE #%d: %d %d\n", i + 1, kiri, kanan);
		}
	}
	
	return 0;
}
