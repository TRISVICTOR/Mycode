#include<stdio.h>

int main(){
	
	int awal = 1;
	int a;
	scanf("%d",&a);
	
	for(int i=0;i<a;i++){
		awal = awal*2+1;
	}
	printf("%d\n",awal);
	
	return 0;
}
