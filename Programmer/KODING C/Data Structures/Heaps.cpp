#include<stdio.h>
#include<stdlib.h>

int heap[100];
int N=1;

int parent(int n){
	return n/2;
}

int leftchild(int n){
	return 2*n;
}

int rightchild(int n){
	return (2*n)+1;
}

void swap(int a, int b){
	int t = heap[a];
	heap[a] = heap[b];
	heap[b] = t;
}

void insert(int num){
	heap[N] = num;
	N++;
	
	int i = N-1;
	int p = parent(i);
	
	while(p >= 1 && heap[p] > heap[i]){
		swap(p,i);
		i = p;
		p = parent(i);
	}
}

int findmin(){
	return heap[1];
}

void deleteMin(){
	if(N == 1){
		return;
	}
	
	N--;
	heap [1] = heap[N];
	
	int i = 1;
	int l = leftchild(i);
	int r = rightchild(i);
	
	while((l < N && heap[l] < heap[i]) || (r < N && heap[r] < heap[i])){
		if(r < N && heap[r] < heap[l]){
			swap(r, i);
			i = r;
		}
		else{
			swap(l, i);
			i = l;
		}
		l = leftchild(i);
		r = rightchild(i);
	}
}

void viewHeap(){
	for(int i=1;i<N;i++){
		printf("%d ",heap[i]);
	}
	printf("\n");
}

int main(){
	
	for(int i=0;i<20;i++){
		int a = rand() % 100;
		insert(a);
		viewHeap();
	}
	printf("\n\n");
	
//	for(int i = 0;i<20;i++){
//		int min = findmin();
//		printf("%2d\n",min);
//		deleteMin();
//		viewHeap();
//	}
	
	return 0;
}
