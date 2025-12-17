#include<stdio.h>

int main(){
	
	char a,b,c;
	scanf("%c %c %c",&a,&b,&c);
	
	if(a<b && a<c){
		printf("1 ");
		if(b<c){
			printf("2 ");
			printf("3\n");
		}
		else{
			printf("3 ");
			printf("2\n");
		}
	}
	else if(b<a && b<c){
		printf("2 ");
		if(a<c){
			printf("1 ");
			printf("3\n");
		}
		else{
			printf("3 ");
			printf("1\n");
		}
	}
	else if(c<a && c<b){
		printf("3 ");
		if(a<b){
			printf("1 ");
			printf("2\n");
		}
		else{
			printf("2 ");
			printf("1\n");
		}
	}
	
	return 0;
}
