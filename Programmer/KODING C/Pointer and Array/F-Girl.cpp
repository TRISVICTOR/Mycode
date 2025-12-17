#include<stdio.h>
#include<string.h>

int main(){
	
	int tc;
	scanf("%d",&tc);getchar();
	
	for(int i=1;i<=tc;i++){
		char arr[100001];
		scanf("%s",&arr);
		
		int hasil=0;
		
		for(int j=0;j<strlen(arr);j++){
			int nilai=1;
			
			for(int k=0;k<j;k++){
				if(arr[j]==arr[k]){
					nilai = 0;
					break;
				}
			}
			
			if(nilai){
				hasil++;
			}
		}
		
		if(hasil%2==0){
			printf("Case #%d: Yay\n",i);
		}
		else{
			printf("Case #%d: Ewwww\n",i);
		}
	}
	
	return 0;
}
