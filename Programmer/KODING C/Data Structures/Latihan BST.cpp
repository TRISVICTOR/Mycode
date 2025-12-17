#include<stdio.h>
#include<stdlib.h>

struct Node{
	int number;
	Node *left;
	Node *right;
} *root;

Node *push(Node *curr, int number){
	if(curr == NULL){
		curr = (Node*)malloc(sizeof(Node));
		curr->number = number;
		curr->left = curr->right = NULL;
	}
	else{
		if(curr->number == number){
			printf("Duplicate\n");
		}
		else if(number < curr->number){
			curr->left = push(curr->left, number);
		}
		else{
			curr->right = push(curr->right, number);
		}
	}
	return curr;
}

void infix(Node *curr){
	if(curr != NULL){
		infix(curr->left);
		printf("%d ",curr->number);
		infix(curr->right);
	}
	if(curr == root){
		printf("\n");
	}
}

void prefix(Node *curr){
	if(curr != NULL){
		printf("%d ",curr->number);
		prefix(curr->left);
		prefix(curr->right);
	}
	if(curr == root){
		printf("\n");
	}
}

void postfix(Node *curr){
	if(curr != NULL){
		postfix(curr->left);
		postfix(curr->right);
		printf("%d ",curr->number);
	}
	if(curr == root){
		printf("\n");
	}
}

void viewTree(Node *curr, int level){
	if(curr != NULL){
		viewTree(curr->right, level+1);
		for(int i=0;i<level;i++){
			printf("\t");
		}
		printf("%d\n", curr->number);
		viewTree(curr->left, level+1);
	}
}

int main(){
	
	for(int i=0;i<10;i++){
		int angka = rand() % 100;
		printf("num : %d\n",angka);
		root = push(root, angka);
	}
	
	viewTree(root,0);
	infix(root);
	prefix(root);
	postfix(root);
	
	return 0;
}
