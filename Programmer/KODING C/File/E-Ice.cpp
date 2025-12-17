#include<stdio.h>

int main(){
	
	FILE *file=fopen("testdata.in","r");
	
	int tc;
	fscanf(file,"%d\n",&tc);
	
	for(int i=0;i<tc;i++){
		int n;
		fscanf(file,"%d\n",&n);
		
		
		int totalBalok=0;
		int a[101];
		for(int j=0;j<n;j++){
			fscanf(file,"%d\n",&a[j]);
			totalBalok+=a[j];
		}
		
		printf("Case #%d: ",i+1);
		
		int keliling=0,luas=0;
		
		luas+=4*totalBalok;
		
		int sisi=0;
		sisi+=2*n;
		sisi+=a[0]+a[n-1];
		
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
				sisi+=a[j]-a[j+1];
			}
			else if(a[j]<a[j+1]){
				sisi+=a[j+1]-a[j];
			}
		}
		keliling=2*sisi;
		
		printf("%d %d\n",keliling,luas);
	}
	
	fclose(file);
	
	return 0;
}
