#include<stdio.h>

int main(){
	
	int a,b;
	scanf("%d %d",&a,&b);
	
	int arr[a][b];
	
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	
	int c;
	scanf("%d",&c);
	
	int d,e,f;
	
	for(int i=0;i<c;i++){
		scanf("%d %d %d",&d,&e,&f);
		arr[d-1][e-1]=f;
	}
	
	for(int i = 0; i<a; i++){
        for(int j = 0; j<b; j++){
            printf("%d", arr[i][j]);
            if(j!=b-1){
            	printf(" ");
			}
        }
        printf("\n");
    }
	
	return 0;
}
