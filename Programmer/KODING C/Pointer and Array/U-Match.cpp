#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=0;i<tc;i++){
		int tc2;
		scanf("%d",&tc2);getchar();
		
		long long int arr[tc2];
		
		for(int j=0;j<tc2;j++){
			scanf("%lld",&arr[j]);getchar();
		}
		
		int a,b;
		scanf("%d %d",&a,&b);getchar();
		
		if(arr[a-1]>arr[b-1]){
			printf("Case #%d : Bibi\n",i+1);
		}
		else if(arr[a-1]<arr[b-1]){
			printf("Case #%d : Lili\n",i+1);
		}
		else{
			printf("Case #%d : Draw\n",i+1);
		}
	}
	
	return 0;
}
