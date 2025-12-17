#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	int kamar[tc];
	
	for(int i=0;i<tc;i++){
		scanf("%d",&kamar[i]);
	}
	
	int hasil=0;
	int a;
	
	for(int i=0;i<tc;i++){
		a=0;
		for(int j=0;j<i;j++){
			if(kamar[i] == kamar[j]){
				a=1;
				break;
			}
		}
		if(a==0){
			hasil++;
		}
	}
	
	printf("%d\n",hasil);
	
	return 0;
}
