#include<stdio.h>
#include<string.h>

int main(){
	
	FILE *file=fopen("testdata.in","r");
	
	int n;
	fscanf(file,"%d\n",&n);
	
	for(int i=0;i<n;i++){
		int mundur;
		fscanf(file,"%d\n",&mundur);
		
		char kalimat[1001];
		fscanf(file,"%[^\n]",&kalimat);
		
		printf("Case #%d: ",i+1);
		
		for(int j=0;j<strlen(kalimat);j++){
			if(kalimat[j]=='0'){
				kalimat[j]='O';
			}
			else if(kalimat[j]=='1'){
				kalimat[j]='I';
			}
			else if(kalimat[j]=='3'){
				kalimat[j]='E';
			}
			else if(kalimat[j]=='4'){
				kalimat[j]='A';
			}
			else if(kalimat[j]=='5'){
				kalimat[j]='S';
			}
			else if(kalimat[j]=='6'){
				kalimat[j]='G';
			}
			else if(kalimat[j]=='7'){
				kalimat[j]='T';
			}
			else if(kalimat[j]=='8'){
				kalimat[j]='B';
			}
		}
		
		for(int j=0;j<strlen(kalimat);j++){
			if(kalimat[j]>='A' && kalimat[j]<='a'){
				kalimat[j]-='A';
				kalimat[j]-=mundur;
				kalimat[j]+=26;
				kalimat[j]%=26;
				kalimat[j]+='A';
			}
			printf("%c",kalimat[j]);
		}
		printf("\n");
	}
	
	fclose(file);
	
	return 0;
}
