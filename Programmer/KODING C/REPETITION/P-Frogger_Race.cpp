#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=1;i<=tc;i++){
		long long int a;
		scanf("%lld",&a);
    
    	long long int langkah = 0;
	    long long int hasil = 0;
	    long long int jarak = 1;
    
	    while(hasil<a){
	        hasil+=jarak;
	        jarak++;
	        langkah++;
	    }
    
    	printf("Case #%d: %lld\n",i,langkah);	
	}
	
	return 0;
}
