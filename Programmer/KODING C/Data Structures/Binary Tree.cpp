#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int number;
	Node *left;
	Node *right;
} *root;

Node *insert(Node *curr, int number){
	if(curr == NULL){
		curr = (Node*)malloc(sizeof(Node));
		curr->number = number;
		curr->left = curr->right = NULL;
	}
	else{
		int input;
		printf("[0/1] : ");	//0 ambil kiri ; 1 ambil kanan
		scanf("%d",&input);
		if(input == 0){
			curr->left = insert(curr->left, number);
			
		}
		else{
			curr->right = insert(curr->right,number);
		}
	}
	return curr;
}

void infix(Node *curr){
	if(curr != NULL){
		infix(curr->left);
		printf("%d ", curr->number);
		infix(curr->right);
	}
	if(curr == root){
		printf("\n");
	}
}

int main(){
	
	for(int i=0;i<10;i++){
		int a = rand()%100;
		printf("num : %d\n",a);
		root = insert(root, a);
	}
	
	infix(root);
	
	return 0;
}
