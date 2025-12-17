#include<stdio.h>

int main(){
	
	FILE *file=fopen("testdata.in","r");
	
	long long int a,b;
	fscanf(file,"%lld %lld\n",&a,&b);
	printf("%lld\n",a+b);
	
	fclose(file);
	
	return 0;
}
