#include<stdio.h>
#include<string.h>
struct urutan{
	int angka;
	char nama[41];
};


int main(){
	
//	FILE *file=fopen("testdata.in","r");
	
//	int tc;
//	fscanf(file,"%d\n",&tc);
	
	int Arr[32]={1,2,3};
	
	for(int i=0;i<3;i++){
		printf("%d",Arr[i]);
	}
	
//	struct urutan plant[tc];
	
//	for(int i=0;i<tc;i++){
//		fscanf(file,"%d#%[^\n]\n",&plant[i].angka,&plant[i].nama);
//	}
	
//	sorting(tc,plant);
	
//	for(int i=0;i<tc;i++){
//		printf("%d %s\n",plant[i].angka,plant[i].nama);
//	}
	
//	fclose(file);
	
	return 0;
}
//void sorting(int tc,struct urutan arr[]){
//	for(int i=0;i<tc;i++){
//		for(int j=0;j<tc-1;j++){
//			if(strcmp(arr[j].nama,arr[j+1].nama)>0){
//				struct urutan c=arr[j];
//				arr[j]=arr[j+1];
//				arr[j+1]=c;
//			}
//		}
//	}
//}
