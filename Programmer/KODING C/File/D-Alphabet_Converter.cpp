#include<stdio.h>
#include<string.h>

int main(){
	
	FILE *file=fopen("testdata.txt","r");
	
	int n;
	fscanf(file,"%d\n",&n);
	
	for(int i=0;i<n;i++){
		char nama[101];
		fscanf(file,"%s\n",&nama);
		
		int tc;
		fscanf(file,"%d\n",&tc);
		
		char temp[26]={0};
		
		for(int j=0;j<tc;j++){
			char a,b;
			fscanf(file,"%c %c\n",&a,&b);
			
			for(int k=0;k<strlen(nama);k++){
				if(nama[k]==a){
					if(temp[a-'A']==0){
						nama[k]=b;
					}
				}
			}
			temp[a-'A']=1;
		}
		
		int alphabet[26]={0};
		for(int j=0;j<strlen(nama);j++){
			int index=nama[j]-'A';
			alphabet[index]++;
		}
		for(int j=0;j<26;j++){
			if(alphabet[j]!=0){
				printf("%c %d\n",j+65,alphabet[j]);
			}
		}
	}
	
	fclose(file);
	
	return 0;
}
