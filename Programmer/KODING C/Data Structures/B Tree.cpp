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

int main(){
	
	
	
	return 0;
}
