#include<stdio.h>
#include<stdbool.h>

int main(){
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=0;i<tc;i++){
		int n;
		scanf("%d",&n);getchar();
		
		int a[n];
		for(int j=0;j<n;j++){
			scanf("%d",&a[j]);getchar();
		}
		
		int coolFac=0;
		bool cool[n];
		for(int j=0;j<n;j++){
			cool[j]=false;
		} 
		
		int sum;
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				sum=a[j]+a[k];
				
				for(int l=0;l<n;l++){
					if(a[l]==sum && l!=j && l!=k && !cool[l]){
						cool[l]=true;
						coolFac++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",i+1,coolFac);	
	}
	
	return 0;
}
