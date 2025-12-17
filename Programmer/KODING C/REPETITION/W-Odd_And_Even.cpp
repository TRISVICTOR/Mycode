#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();

	for(int i=0;i<tc;i++){
		int a;
		scanf("%d",&a);getchar();
		int ganjil = 0;
		int genap = 0;
		
		for(int j=0;j<a;j++){
			int b;
			scanf("%d",&b);
			
			if(b%2==0){
				genap++;
			}
			else{
				ganjil++;
			}
		}
		printf("Odd group : %d integer(s).\n",ganjil);
		printf("Even group : %d integer(s).\n\n",genap);
	}
	
	return 0;
}
