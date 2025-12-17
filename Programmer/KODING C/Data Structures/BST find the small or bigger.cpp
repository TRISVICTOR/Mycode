#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int number;
	int height;
	Node *right;
	Node *left;
} *root;

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
		else if(curr->number > number){
			curr->left = insert(curr->left,number);
		}
		else{
			curr->right = insert(curr->right,number);
		}
	}
	return curr;
}

int FindSmall(Node *root){
	while(root->left != NULL){
		root = root->left;
	}
	return root->number;
}

int FindBig(Node *root){
	while(root->right != NULL){
		root = root->right;
	}
	return root->number;
}

int main(){
	
	Node *root = NULL;
	int number;
	for(int i=0;i<5;i++){
		scanf("%d",&number);
		root = insert(root, number);
	}
	
	int besar = FindBig(root);
	printf("%d\n",besar);
	
	int kecil = FindSmall(root);
	printf("%d\n",kecil);
	
	return 0;
}
