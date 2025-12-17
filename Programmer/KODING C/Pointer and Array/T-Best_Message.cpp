#include <stdio.h>
#include <string.h>

int main(){
	
	int tc;
	scanf("%d",&tc); getchar();
	
	char a[1001];
	for(int i =1;i<=tc;i++){
		scanf("%s",a);getchar();
		
		char b[1001];
		char c[1001];
		
		for(int j = 0;j<strlen(a);j++){
			if(a[j] == 'A' || a[j] == 'E' || a[j] == 'I' || a[j] == 'U' || a[j] == 'O'){
				b[j] = a[j];
				c[j] = '0';
			}
			else{
				int d = 0;
				if(a[j] >='B' && a[j] <= 'D'){
					d = a[j] - 'A';
					b[j] = 'A';
				}
				else if(a[j] >='F' && a[j] <= 'H'){
					d = a[j] - 'E';
					b[j] = 'E';
				}
				else if(a[j] >='J' && a[j] <= 'N'){
					d = a[j] - 'I';
					b[j] = 'I';
				}
				else if(a[j] >='P' && a[j] <= 'T'){
					d = a[j] - 'O';
					b[j] = 'O';
				}
				else if(a[j] >='V' && a[j] <= 'Z'){
					d = a[j] - 'U';
					b[j] = 'U';
				}
				c[j] = d + '0';
		}
	}
	
		b[strlen(a)] = '\0';
		c[strlen(a)] = '\0';
		
		printf("Case #%d:\n",i);
		printf("%s\n",b);
		printf("%s\n",c);
	
	}
	return 0;
}
