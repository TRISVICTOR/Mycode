#include<stdio.h>

int main(){
	
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	long long int j[a];
	int hasil=0;
	
	for(int i=0;i<a;i++){
		scanf("%lld",&j[i]);getchar();
	}
	
	for(int k=0;k<a;k++){
		if(j[k]<b){
			hasil++;
		}
	}
	
	printf("%d\n",hasil);
	
	return 0;
}
