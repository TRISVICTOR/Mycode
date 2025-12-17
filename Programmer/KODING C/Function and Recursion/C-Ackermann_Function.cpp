#include<stdio.h>

int hitung(int m,int n){
	if(m==0){
		return n+1;
	}
	if(m>0 && n==0){
		return hitung(m-1,1);
	}
	if(m>0 && n>0){
		return hitung(m-1,hitung(m,n-1));
	}
}

int main(){
	
	int m,n;
	scanf("%d %d",&m,&n);
	
	printf("result: %d\n",hitung(m,n));
	
	return 0;
}
