#include<stdio.h>
#include<string.h>

int main(){
    
    char teks[100];
    scanf("%s",teks); getchar();
    
    for(int i=0;i<strlen(teks);i++){
    	char a = teks[i];
    	if(a >= 'a' && a <= 'z'){
    		teks[i] = ((a - 'a' + 13) % 26) + 'a';
		}
		else if(a >= 'A' && a <= 'Z'){
			teks[i] = ((a - 'A' + 13) % 26) + 'A';
		}
	}
	
	printf("%s",teks);
  	
    return 0;
}
