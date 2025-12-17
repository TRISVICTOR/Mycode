#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	int n,lili,bibi;
	char s[101];
	
	while(tc--){
		scanf("%d",&n);
		scanf("%s",s);
		
		lili=0;
		bibi=0;
		
		for(int i=0;i<n;i++){
			if(s[i]=='L'){
				lili++;
			}
			else if(s[i]=='B'){
				bibi++;
			}
		}
		if(lili>bibi){
			printf("Lili\n");
		}
		else if(bibi>lili){
			printf("Bibi\n");
		}
		else{
			printf("None\n");
		}
	}
	
	return 0;
}
