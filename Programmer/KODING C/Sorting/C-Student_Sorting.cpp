#include<stdio.h>
#include<string.h>

struct urutan{
	char angka[11];
	char nama[41];
};

void sorting(int tc,struct urutan arr[]){
	
	for(int i=0;i<tc;i++){
		for(int j=0;j<tc-1;j++){
			if(strcmp(arr[j].angka,arr[j+1].angka)>0){
				struct urutan c=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=c;
			}
		}
	}
	
}

int main(){
	
	FILE *file=fopen("testdata.in","r");
	
	int tc;
	fscanf(file,"%d\n",&tc);
	
	struct urutan plant[tc];
	
	for(int i=0;i<tc;i++){
		fscanf(file,"%s %[^\n]\n",&plant[i].angka,&plant[i].nama);
	}
	
	sorting(tc,plant);
	
	for(int i=0;i<tc;i++){
		printf("%s %s\n",plant[i].angka,plant[i].nama);
	}
	
	fclose(file);
	
	return 0;
}
