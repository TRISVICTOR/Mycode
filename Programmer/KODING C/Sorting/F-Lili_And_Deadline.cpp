#include<stdio.h>
#include<string.h>

struct Data{
	char matkul[11];
	int nilai;
};

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	Data woke[tc];
	
	for(int i=0;i<tc;i++){
		scanf("%s %d",&woke[i].matkul,&woke[i].nilai);
	}
	
	for(int i=0;i<tc;i++){
		for(int j=0;j<tc-1;j++){
			if(woke[j].nilai>woke[j+1].nilai || (woke[j].nilai == woke[j+1].nilai && strcmp(woke[j].matkul, woke[j+1].matkul) > 0)){
				struct Data c=woke[j];
				woke[j]=woke[j+1];
				woke[j+1]=c;
			}
		}
	}
	
	for(int i=0;i<tc;i++){
		printf("%s\n",woke[i].matkul);
	}
	
	return 0;
}
