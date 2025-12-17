#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	int hasil = 0;
	
	for(int i=0;i<tc;i++){
		int a;
		scanf("%d",&a);
		hasil+=a;
		if(hasil==9) hasil+=12;
		else if(hasil==33) hasil+=9;
		else if(hasil==76) hasil+=16;
		else if(hasil==53) hasil-=16;
		else if(hasil==80) hasil-=21;
		else if(hasil==97) hasil-=9;
	}
	
	printf("%d\n",hasil);
	
	return 0;
}
