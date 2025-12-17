#include<stdio.h>

int main(){
	
	int tc;
	int angka=0;
	int hasil=0;
	scanf("%d",&tc);
	
	int a[tc];
	int b[1001]={0};
	
	for(int i=0;i<tc;i++){
		scanf("%d",&a[i]);
		if(a[i]>angka){
			angka=a[i];
		}
		b[a[i]]++;
	}
	
	for(int i=0;i<=angka;i++){
		if(b[i]>hasil){
			hasil=b[i];
		}
	}
	
	printf("%d\n",hasil);
	
	return 0;
}
