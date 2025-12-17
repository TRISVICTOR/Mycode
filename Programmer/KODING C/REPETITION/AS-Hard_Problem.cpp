#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		int soal;
		scanf("%d",&soal);
		int hasil=0;
		
		char a[1001];
		char b[1001];
		scanf("%s",a);
		scanf("%s",b);
		
		for(int j=0;j<soal;j++){
			if(a[j]==b[j]){
				hasil++;
			}
		}
		
		printf("Case #%d: %d\n",i,(hasil*100)/soal);
	}
	
	return 0;
}
