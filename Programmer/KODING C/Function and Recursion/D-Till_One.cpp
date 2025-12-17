#include<stdio.h>

int hitung(int N){
	if(N==1){
		return 1;
	}
	if(N%2==0){
		return hitung(N/2);
	}
	if(N%2!=0){
		return hitung(N-1)+hitung(N+1);
	}
}

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		int N;
		scanf("%d",&N);
		printf("Case #%d: %d\n",i+1,hitung(N));
	}
	
	return 0;
}
