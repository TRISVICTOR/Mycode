#include<stdio.h>
#include<math.h>

int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}

int main(){
	
	double X;
	scanf("%lf",&X);
	long long int A,B;
	scanf("%lld %lld",&A, &B);
	long long int parameter = 1;
	
	if(X < A || X > B){
		printf("-1\n");
	}
	else{
		while(fabs(X-(int)X) > 1e-9){
			X *= 10;
			parameter*= 10;
		}
		
		int Y = (int)X;
		int GCD = gcd(parameter, Y);
		
		Y/=GCD;
		parameter/=GCD;
		
		printf("%lld\n",parameter);
		
		for(int i = 0;i<Y%parameter;i++){
			printf("%lld ",Y/parameter + 1);
		}
		for(int i = 0;i < parameter - Y%parameter;i++){
			printf("%lld ",Y/parameter);
		}
		
		printf("\n");
	}
	
	return 0;
}
