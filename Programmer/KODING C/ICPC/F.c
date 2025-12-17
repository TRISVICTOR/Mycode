#include<stdio.h>

int main(){
	
	float X;
	scanf("%f",&X);
	int A,B;
	scanf("%d %d",&A, &B);
	
	float compar;
	int i;
	for (i = 1; i < 1000; i++) {
    	compar = X * i;
    	if(compar == (int)compar){
    		break;
		}
	}
	
	int arr[10];
	int targetStar = compar;
	for(int j = 0;j<i;j++){
		int kiri = i-j-1;
		int tengah = kiri*A;
		int take = B;
		
		if(targetStar - take < tengah){
			take = targetStar - tengah;
		}
		
		if(take < A){
			take = A;
		}
		
		arr[j] = take;
		targetStar -= take;
	}
	
	if(i > 5){
		printf("-1");
	}
	else{
		for(int j = 0;j<i;j++){
			printf("%d ",arr[j]);
		}
	}
	
	printf("\n");
	
	return 0;
}

