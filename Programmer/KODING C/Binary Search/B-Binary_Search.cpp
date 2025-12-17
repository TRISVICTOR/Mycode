#include<stdio.h>

double formula(double jumlah){
	double hasil=1.0/6.0*jumlah*(jumlah+1)*(2*jumlah+1);
	return hasil;
}

double binary(double left, double right, double M){
	double a;
	while(left<=right){
		long long mid=left+(right-left)/2;
		double b=formula(mid);
		
		if(b>=M){
			a=mid;
			right=mid-1;
		}
		else{
			left=mid+1;
		}
	}
	return a;
}

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		double M;
		scanf("%lf",&M);
		
		double N=binary(0,10000000001,M);
		printf("Case #%d: %.0lf\n",i,N);
	}
	
	return 0;
}
