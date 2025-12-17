#include<stdio.h>

void knight(int matrix[8][8], int X1, int Y1, int X2, int Y2, int s, int *langkah){
	if(X1==X2 && Y1==Y2){
		if(s<*langkah){
			*langkah=s;
		}
		return;
	}
	
	if(s>=matrix[X1][Y1] || s>=*langkah){
		return;
	}
	
	matrix[X1][Y1]=s;
	
	if(X1<7 && Y1<6) knight(matrix,X1+1,Y1+2,X2,Y2,s+1,langkah);
	if(X1<7 && Y1>1) knight(matrix,X1+1,Y1-2,X2,Y2,s+1,langkah);
	if(X1>0 && Y1<6) knight(matrix,X1-1,Y1+2,X2,Y2,s+1,langkah);
	if(X1>0 && Y1>1) knight(matrix,X1-1,Y1-2,X2,Y2,s+1,langkah);
	if(X1<6 && Y1<7) knight(matrix,X1+2,Y1+1,X2,Y2,s+1,langkah);
	if(X1<6 && Y1>0) knight(matrix,X1+2,Y1-1,X2,Y2,s+1,langkah);
	if(X1>1 && Y1<7) knight(matrix,X1-2,Y1+1,X2,Y2,s+1,langkah);
	if(X1>1 && Y1>0) knight(matrix,X1-2,Y1-1,X2,Y2,s+1,langkah);
}

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=0;i<tc;i++){
		char X1,X2;
		int Y1,Y2;
		scanf("%c%d %c%d",&X1,&Y1,&X2,&Y2);
		getchar();
		
		X1-='A';
		X2-='A';
		Y1--;
		Y2--;
		
		int matrix[8][8];
		for(int j=0;j<8;j++){
			for(int k=0;k<8;k++){
				matrix[j][k]=100;
			}
		}
		
		int langkah=64;
		knight(matrix,X1,Y1,X2,Y2,0,&langkah);
		
		printf("Case #%d: %d\n",i+1,langkah);
	}
	
	return 0;
}
