#include<stdio.h>
#include<string.h>

struct Data{
	char name[41];
	char plant[41];
};

int main(){
	
	FILE *file=fopen("testdata.in","r");
	
	int n;
	fscanf(file,"%d\n",&n);
	
	struct Data plants[n];
	for(int i=0;i<n;i++){
		fscanf(file,"%[^#]#%[^\n]\n",plants[i].name,plants[i].plant);
	}
	
	int tc;
	fscanf(file,"%d\n",&tc);
	
	for(int t=0;t<tc;t++){
		char name[41];
		fscanf(file,"%[^\n]\n",name);
		
		printf("Case #%d: ",t+1);
		bool found=false;
		
		for(int i=0;i<n;i++){
			if(strcmp(plants[i].name,name)==0){
				printf("%s\n",plants[i].plant);
				found=true;
				break;
			}
		}
		if(found==false){
			printf("N/A\n");
		}
	}
	
	fclose(file);
	
	return 0;
}
