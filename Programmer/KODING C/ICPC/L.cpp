#include<stdio.h>
#include<string.h>

int main(){
	
	int N,K,M,L;
	scanf("%d",&N);
	scanf("%d",&K);
	scanf("%d",&M);
	scanf("%d",&L);
	int arr[N];
	for(int i = 0;i<N;i++){
		int s;
		scanf("%d",&s);
		if(s<M){
			arr[i] = s;
		}
	}
	
	
	
	return 0;
}
