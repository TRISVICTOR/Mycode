#include<stdio.h>
#include<string.h>
struct Data{
	char penghargaan[1001];
	char nama[1001];
	long long int harga;
};

void sorting(int b,struct Data Woke[]){
	for(int i=0;i<b;i++){
		for(int j=0;j<b-1;j++){
			if(Woke[j].harga<Woke[j+1].harga || (Woke[j].harga == Woke[j+1].harga && strcmp(Woke[j].penghargaan, Woke[j+1].penghargaan) > 0)){
				struct Data c=Woke[j];
				Woke[j]=Woke[j+1];
				Woke[j+1]=c;
			}
		}
	}
}

int main(){
	
	FILE *file=fopen("testdata.in","r");
	struct Data Woke[101];
	int b=0;
	while(!feof(file)){
		fscanf(file, "%[^#]#%[^#]#%lld\n",Woke[b].penghargaan , Woke[b].nama, &Woke[b].harga);
		b++;
    }
	
	sorting(b, Woke);
	
	for(int i=0;i<b;i++){
		printf("%s by %s - %lld\n",Woke[i].penghargaan,Woke[i].nama,Woke[i].harga);
	}
	
	
	fclose(file);
	
	return 0;
}
