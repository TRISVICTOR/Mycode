#include<stdio.h>

int arr[100];

void makeSet(int n){
	for(int i = 0;i<n;i++){
		arr[i] = i;
		printf("%d\n",i);
	}
}

int findSet(int n){
	if(n == arr[n]){
		return n;
	}
	return arr[n] = findSet(arr[n]);
}

void unionSet(int a, int b){
	int pa = findSet(a);
	int pb = findSet(b);
	arr[pa] = pb;
}

int main(){
	
	makeSet(10);
	
	unionSet(2,1);
	unionSet(3,1);
	unionSet(4,2);
	
	printf("\n");
	
	for(int i=0;i<10;i++){
		printf("parent %d = %d\n", i, findSet(i));
	}
	
	unionSet(6, 5);
	unionSet(7, 5);
	unionSet(8, 5);
	unionSet(8, 2);
	
	printf("\n");
	
	for(int i=0;i<10;i++){
		printf("parent %d = %d - %d\n", i, arr[i], findSet(i));
	}
	
	return 0;
}
