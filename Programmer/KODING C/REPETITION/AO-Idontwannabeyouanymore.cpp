#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=1;i<=tc;i++){
		int a;
		scanf("%d",&a);getchar();
		
		char b[a+1];
		char c[a+1];
		scanf("%[^\n]",&b);getchar();
		int d=0;
		
		for(int j=0;j<a;j++){
			if(b[j]>='a' && b[j]<='z'){
				c[d]=b[j];
				d++;
			}
		}
		c[d]='\0';
		printf("Case #%d: %s\n",i,c);
	}
	
	return 0;
}
