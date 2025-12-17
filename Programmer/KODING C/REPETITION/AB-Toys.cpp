#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int hasil = 0;
		int N;
		scanf("%d",&N);
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		for(int j=1;j<=N;j++){
			if(j%a==0) hasil++;
			else if(j%b==0) hasil++;
			else if(j%c==0) hasil++;
			else if(j%d==0) hasil++;
		}
		printf("Case #%d: %d\n",i,hasil);
	}
	
	return 0;
}
