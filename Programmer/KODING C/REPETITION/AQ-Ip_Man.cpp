#include<stdio.h>
#include<string.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	char a[1001];
	
	for(int k=1;k<=tc;k++){
		scanf("%s",&a);
		
		int hasil=0;
		for(int i=0;i<strlen(a);i++){
			if(a[i]>='0' && a[i]<='9'){
				if(a[i+1]=='.' && a[i+2]!='.'){
					hasil++;
				}
			}
		}
		if(hasil==5){
			printf("Case #%d: YES\n",k);
		}
		else{
			printf("Case #%d: NO\n",k);
		}
	}
	
	return 0;
}
