#include<stdio.h>

void fibostring(int n, char f0, char f1){
	if(n == 0){
		printf("%c",f0);
	}else if (n==1){
		printf("%c",f1);
	}else{
		fibostring(n-1, f0, f1);
		fibostring(n-2, f0,f1);
	}
}

int main(){
	int tc;
	scanf("%d",&tc); getchar();	
	
	for(int k = 1 ; k <= tc; k++){
		int n;
		char f0, f1;
		scanf("%d %c %c",&n, &f0, &f1); getchar();
		printf("Case #%d: ",k);
		fibostring(n,f0,f1);
		printf("\n");
	}
	
	return 0;
}
