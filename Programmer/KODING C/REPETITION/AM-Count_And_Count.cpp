#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	int a;
	
	for(int i=1;i<=tc;i++){
		scanf("%d",&a);
		printf("Case #%d:\n",i);
		
		int angka=1;
		
		for(int j=0;j<a;j++){
			if(angka%3==0 || angka%5==0 && angka%15!=0){
				printf("%d Jojo\n",angka);
			}
			else{
				printf("%d Lili\n",angka);
			}
			angka++;
		}
	}
	
	return 0;
}
