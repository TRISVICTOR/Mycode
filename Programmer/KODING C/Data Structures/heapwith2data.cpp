#include<stdio.h>

struct Node{
	int num;
	char name[100];
};

Node heap[100];
int N = 1;

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
	Node t = heap[a];
	heap[a] = heap[b];
	heap[b] = t;
}

void insert(Node temp){
	heap[N] = temp;
	N++;
	
	int i = N-1;
	int p = parent(i);
	
	while(p >= 1 && heap[p].num > heap[i].num){
		swap(p,i);
		i = p;
		p = parent(i);
	}
}

int main(){
	
	
	
	return 0;
}
