#include<stdio.h>
#include<string.h>

struct Data{
	char lokasi[1001];
	double suhu;
	char huruf;
};

void sorting(int b,struct Data Woke[]){
	for(int i=0;i<b;i++){
		for(int j=0;j<b-1;j++){
			if(Woke[j].suhu>Woke[j+1].suhu || (Woke[j].suhu == Woke[j+1].suhu && strcmp(Woke[j].lokasi, Woke[j+1].lokasi) > 0)){
				struct Data c=Woke[j];
				Woke[j]=Woke[j+1];
				Woke[j+1]=c;
			}
		}
	}
}

int main(){
	
	FILE *file=fopen("testdata.in","r");
	
	Data Woke[101];
	
	int b=0;
	while(!feof(file)){
		fscanf(file, "%[^#]#%lf#%c\n",Woke[b].lokasi , &Woke[b].suhu, &Woke[b].huruf);
		b++;
    }
    
    for(int i=0;i<b;i++){
    	if(Woke[i].huruf=='F'){
    		Woke[i].suhu=(Woke[i].suhu-32)*5/9;
		}
	}
	
	sorting(b,Woke);
	
	for(int i=0;i<b;i++){
		if(Woke[i].huruf=='F'){
			printf("%s is %.2lf%c\n",Woke[i].lokasi,(Woke[i].suhu*9)/5+32,Woke[i].huruf);
		}
		else{
			printf("%s is %.2lf%c\n",Woke[i].lokasi,Woke[i].suhu,Woke[i].huruf);
		}
	}
    
    fclose(file);
	
	return 0;
}
