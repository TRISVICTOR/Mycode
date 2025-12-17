#include<stdio.h>
#include<string.h>

int main(){
	
	int damage,musuh;
	scanf("%d %d",&damage,&musuh);
	
	int a[damage];
	int b[musuh];
	
	int size=sizeof(b)/sizeof(b[0]);
	
	int besar=0;
	int hasil=0;
	
	for(int i=0;i<damage;i++){
		scanf("%d",&a[i]);
		if(a[i]>besar){
			besar=a[i];
		}
	}
	
	for(int i=0;i<musuh;i++){
		scanf("%d",&b[i]);
		if(besar>b[i]){
			hasil++;
		}
	}
	
	if(hasil==size){
		printf("The dark secret was true\n");
	}
	else{
		printf("Sercret debunked\n");
	}
	
	return 0;
}
