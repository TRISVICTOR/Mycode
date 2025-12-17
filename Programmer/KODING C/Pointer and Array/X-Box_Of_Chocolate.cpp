#include<stdio.h>

int main(){

	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		int a,b;
		scanf("%d %d",&a,&b);getchar();
		
		long long int hasil=0;
		long long int cek=0;
		
		int matrix[a][b];
		for(int j=0;j<a;j++){
			for(int k=0;k<b;k++){
				scanf("%lld",&matrix[j][k]);
				if(matrix[j][k]>cek){
					cek=matrix[j][k];
				}
			}
			hasil+=cek;
			cek=0;
		}
		
		printf("Case #%d: %lld\n",i+1,hasil);
	}

	return 0;
}
