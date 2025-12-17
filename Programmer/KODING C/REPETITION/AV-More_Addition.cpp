#include<stdio.h>

int main(){
	
    int a;
    scanf("%d",&a);
    int hasil = 0;

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= a - i; j++){
            int b = a - i - j;
            if(b >= 0){ 
                hasil++;
            }
        }
    }

    printf("%d\n",hasil);
    
    return 0;
}
