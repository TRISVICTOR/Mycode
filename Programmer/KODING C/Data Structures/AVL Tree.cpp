#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int number;
	int height;
	Node *right;
	Node *left;
} *root;

int tinggi(Node *curr){
	if(curr == NULL){
		return 0;
	}
	return curr->height;
}

int max(int a, int b){
	return a>b ? a:b;
}

Node *RightRotation(Node *curr){
	Node *T = curr->left;
	Node *T2 = T->right;
	
	T->right = curr;
	curr->left = T2;
	
	curr->height = max(tinggi(curr->left), tinggi(curr->right)) + 1;
	T->height = max(tinggi(T->left),tinggi(T->right)) + 1;
	
	return T;
}

Node *LeftRotation(Node *curr){
	Node *T = curr->right;
	Node *T2 = T->left;
	
	T->left = curr;
	curr->right = T2;
	
	curr->height = max(tinggi(curr->left), tinggi(curr->right)) + 1;
	T->height = max(tinggi(T->left),tinggi(T->right)) + 1;
	
	return T;
}

int BalanceFactory(Node *curr){
	if(curr == NULL){
		return 0;
	}
	return tinggi(curr->left)-tinggi(curr->right);
}



Node *insert(Node *curr, int number){
	if(curr == NULL){
		curr = (Node*)malloc(sizeof(Node));
		curr->number = number;
		curr->left = curr->right = NULL;
		return curr;
	}
	else{
		if(curr->number == number){
			printf("Duplicate\n");
		}
		else if(number > curr->number){
			curr->right = insert(curr->right, number);
		}
		else{
			curr->left = insert(curr->left, number);
		}
	}
	
	curr->height = max(tinggi(curr->left), tinggi(curr->right)) + 1;
	
	int b = BalanceFactory(curr);
	
	if(b>1 && number<curr->left->number){ //LEFTLEFT(SINGLE ROTATION)
		curr = RightRotation(curr);
	}
	
	if(b<-1 && number>curr->right->number){ //RIGHTRIGHT(SINGLE ROTATION)
		curr = LeftRotation(curr);
	}
	
	if(b>1 && number>curr->left->number){
		curr->left = LeftRotation(curr->left); //LEFTRIGHT
		curr = RightRotation(curr);
	}
	
	if(b<-1 && number<curr->right->number){
		curr->right = RightRotation(curr->right); //RIGHTLEFT
		curr = LeftRotation(curr);
	}
	
	return curr;
}

void TreeView(Node *curr, int level){
	if(curr != NULL){
		TreeView(curr->right, level+1);
		for(int i=0;i<level;i++){
			printf(" ");
		}
		printf("+ %d\n", curr->number);
		TreeView(curr->right, level+1);
		if(curr == root){
			printf("\n");
		}
	}
}

int main(){
	
	int numbers[10]={17, 11, 5, 2, 1, 3, 13, 18, 19};
	for(int i=0;i<9;i++){
		root = insert(root, numbers[i]);
		TreeView(root, 0);
	}
	
	return 0;
}
