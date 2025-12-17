#include<stdio.h>

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		char jalan[a+1];
		scanf("%s",&jalan);
		
		int nafas=b;
		bool hidup=false;
		
		for(int j=0;j<a;j++){
			nafas--;
			
			if(nafas<0){
				hidup=false;
				break;
			}
			if(b>=a){
				hidup=true;
				break;
			}
			if(jalan[j]=='1'){
				int tangga;
				for(int k=a-1;k>=j;k--){
					if(jalan[k]=='1'){
						tangga=k;
						break;
					}
				}
				if(tangga==j){
					hidup=false;
					break;
				}
				if(a-1-tangga<b){
					hidup=true;
					break;
				}
			}
		}
		if(hidup==true){
			printf("Case #%d: Alive\n",i+1);
		}
		else if(hidup==false){
			printf("Case #%d: Dead\n",i+1);
		}
	}
	
	return 0;
}
