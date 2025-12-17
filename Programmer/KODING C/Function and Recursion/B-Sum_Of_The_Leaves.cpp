#include<stdio.h>

void printtree(int tree[],int n,int index, int value){
	
	if(index>n){
		return;
	}
	
	value=value+tree[index];
	
	if(2*index>n && 2*index+1>n){
		printf("%d\n",value);
		return;
	}
	
	printtree(tree,n,2*index,value);
	printtree(tree,n,2*index+1,value);
}

int main(){
	
	int tc;
	scanf("%d",&tc);
	
	for(int i=0;i<tc;i++){
		int n;
		scanf("%d",&n);
		
		int tree[n+1];
		for(int i=1;i<=n;i++){
			scanf("%d",&tree[i]);
		}
		
		printf("Case #%d:\n",i+1);
		printtree(tree,n,1,0);
	}
	
	return 0 ;
}
