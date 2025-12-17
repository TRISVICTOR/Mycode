#include<stdio.h>
#include<string.h>

struct list{
	char NIM[11];
	char NAMA[21];
};

int main(){
	
	FILE *fp=fopen("testdata.in","r");
	
	if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
	int tc;
	fscanf(fp,"%d",&tc);
	
	struct list Data[tc];
	
	for(int i=0;i<tc;i++){
		fscanf(fp,"%s %[^\n]\n",&Data[i].NIM,&Data[i].NAMA);
	}
	
	int cari;
	fscanf(fp,"%d\n",&cari);
	
	for(int i=0;i<cari;i++){
		char nim[11];
		fscanf(fp,"%s\n",&nim);
		
		int ketemu=0;
		
		for(int j=0;j<tc;j++){
			if(strcmp(nim,Data[j].NIM)==0){
				printf("Case #%d: %s\n",i+1,Data[j].NAMA);
				ketemu=1;
				break;
			}
		}
		if(!ketemu){
			printf("Case #%d: N/A\n",i+1);
		}
	}
	
	fclose(fp);
	
	return 0;
}
