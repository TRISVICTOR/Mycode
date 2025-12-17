#include <stdio.h>

int main() {
    int tc;
    scanf("%d",&tc);
    
    for(int i=0;i<tc;i++){
	   	int a;
		scanf("%d",&a);
		
		for(int k=0;k<a;k++){ 
		    for(int j=0;j<a-k-1;j++){
		        printf("#");
		    }
		    
			for(int j=0;j<2*k+1;j++){
				printf("*");
			}
			
			printf("\n");
		}
	}

    return 0;
}
