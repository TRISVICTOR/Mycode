#include <stdio.h>

int main(){
	
	int a;
	scanf("%d",&a);
	long long int hasil = 0;
	
	for(int i=0;i<a;i++){
		int a;
		scanf("%d",&a);
		hasil+=a;
	}
	
	printf("%d\n",hasil);
	
    return 0;
}
