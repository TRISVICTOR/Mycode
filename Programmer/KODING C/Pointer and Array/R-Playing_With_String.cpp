#include<stdio.h>
#include<string.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	
	for(int i=1;i<=tc;i++){
		char awal[1005];
		scanf("%s",awal);getchar();
		
		int a;
		scanf("%d",&a);getchar();
		
		
		for(int j=0;j<a;j++){
			char b,c;
			scanf("%c %c",&b,&c);getchar();
			for(int k=0;k<strlen(awal);k++){
				if(awal[k]==b){
					awal[k]=c;
				}
			}
		}
		
		printf("Case #%d: %s\n",i,awal);
		
	}
	
	return 0;
}
