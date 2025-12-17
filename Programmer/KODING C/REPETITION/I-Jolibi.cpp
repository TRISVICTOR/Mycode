#include <stdio.h>

int main() {
    
    int N;
    scanf("%d",&N);
    
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    
    int nilai=0;
    
    for(int i=0;i<N;i++){
    	int lain;
    	scanf("%d",&lain);
    	nilai+=lain;
	}
	
	int rata=(a+b+c+nilai)/(3+N);
	
	if(a>=rata && b>=rata && c>=rata){
		printf("Jojo lolos\n");
		printf("Lili lolos\n");
		printf("Bibi lolos\n");
	}
	
	else if(a<=rata && b>=rata && c>=rata){
		printf("Jojo tidak lolos\n");
		printf("Lili lolos\n");
		printf("Bibi lolos\n");
	}
	
	else if(a>=rata && b<=rata && c>=rata){
		printf("Jojo lolos\n");
		printf("Lili tidak lolos\n");
		printf("Bibi lolos\n");
	}
	
	else if(a<=rata && b<=rata && c>=rata){
		printf("Jojo tidak lolos\n");
		printf("Lili tidak lolos\n");
		printf("Bibi lolos\n");
	}
	
	else if(a<=rata && b>=rata && c<=rata){
		printf("Jojo tidak lolos\n");
		printf("Lili lolos\n");
		printf("Bibi tidak lolos\n");
	}
	
	else if(a>=rata && b<=rata && c<=rata){
		printf("Jojo lolos\n");
		printf("Lili tidak lolos\n");
		printf("Bibi tidak lolos\n");
	}
	
	else if(a>=rata && b>=rata && c<=rata){
		printf("Jojo lolos\n");
		printf("Lili lolos\n");
		printf("Bibi tidak lolos\n");
	}
	
	else if(a<=rata && b<=rata && c<=rata){
		printf("Jojo tidak lolos\n");
		printf("Lili tidak lolos\n");
		printf("Bibi tidak lolos\n");
	}

    return 0;
}
