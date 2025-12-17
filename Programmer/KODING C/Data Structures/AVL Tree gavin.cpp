#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#define max(a, b) ((a > b) ? a : b)

struct Node{
	int num;
	char name[101];
	Node *left;
	Node *right;
	int height;
}*root = NULL;

Node *createNode(int num, const char *name){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode -> num = num;
	strcpy(newNode -> name, name);
	newNode -> left = NULL;
	newNode -> right = NULL;
	newNode -> height = 1;
	return newNode;
}

int max(int a, int b){
	return a > b ? a : b;
}

int height(Node *root){
	if(root == NULL){
		return 0;
	}
	return root -> height;
}

int getBalance(Node *root){
	if(root == NULL){
		return 0;
	}
	return height(root -> left) - height(root -> right);
}

Node *rightRotate(Node* root){
	Node *x = root -> left;
	Node *sub_x = x -> right;
	
	x -> right = root;
	root -> left = sub_x;
	
	root -> height = 1 + max(height(root -> left), height(root -> right));
	x -> height = 1 + max(height(x -> left), height(x -> right));
	
	return x;
}

Node *leftRotate(Node *root){
	Node *x = root -> right;
	Node *sub_x = x -> left;
	
	x -> left = root;
	root -> right = sub_x;
	
	root -> height = 1 + max(height(root -> left), height(root -> right));
	x -> height = 1 + max(height(x -> left), height(x -> right));
	
	return x;
}

Node *insert(Node* root, int num, const char *name){
	if(root == NULL){
		return createNode(num, name);
	}
	if(num < root -> num){
		root -> left = insert(root -> left, num, name);
	}
	else{
		root -> right = insert(root -> right, num, name);
	}
	
	root -> height = 1 + max(height(root -> left), height(root -> right));
	
	int balance = getBalance(root);
	
	if(balance > 1 && num < root -> left -> num){
		return rightRotate(root);
	}
	if(balance > 1 && num > root -> left -> num){
		root -> left = leftRotate(root -> left);
		return rightRotate(root);
	}
	if(balance < -1 && num < root -> right -> num){
		root -> right = rightRotate(root -> right);
		return leftRotate(root);
	}
	if(balance < -1 && num > root -> right -> num){
		return leftRotate(root);
	}
	return root;
}

void preOrder(Node* root){
	if(root == NULL){
		return;
	}
	printf("%d - %s\n", root -> num, root -> name);
	preOrder(root -> left);
	preOrder(root -> right);
}

Node *search(Node* root, int num){
	if(root == NULL){
		return NULL;
	}
	if(num < root -> num){
		return search(root -> left, num);
	}
	else if(num > root -> num){
		return search(root -> right, num);
	}
	return root;
}

Node *remove(Node *root, int num){
	if(root == NULL){
		printf("Not found\n");
		return NULL;
	}
	if(num < root -> num){
		root -> left = remove(root -> left, num);
	}
	else if(num > root -> num){
		root -> right = remove(root -> right, num);
	}
	else{
		if(root -> left == NULL || root -> right == NULL){
			Node *temp = NULL;
			if(root -> left){
				temp = root -> left;
			}
			else{
				temp = root -> right;
			}
			
			free(root);
			root = temp;
			if(root == NULL){
				return NULL;
			}
		}
		else{
			Node *successor = root -> right;
			while(successor -> left != NULL){
				successor = successor -> left;
			}
			root -> num = successor -> num;
			strcpy(root->name, successor->name);
			
			root -> right = remove(root -> right, successor -> num);
		}
	}
	//update height & balancing root
	root -> height = 1 + max(height(root -> left), height(root -> right));
	int balance = getBalance(root);
	//left left case
	if(balance > 1 && getBalance(root-> left) >= 0){ //balance > 1 codong ke kiri
		return rightRotate(root);
	}
	//left right case
	else if(balance > 1 && getBalance(root -> left) < 0){
		root -> left = leftRotate(root -> left);
		return rightRotate(root);
	}
	//right right case
	else if(balance < -1 && getBalance(root -> right) <= 0){
		return leftRotate(root);
	}
	//right left case
	else if(balance < -1 && getBalance(root -> right) > 0){
		root -> right = rightRotate(root -> right);
		return leftRotate(root);
	}
	return root;
}

int main(){
	root = insert(root, 13, "Potato");
	root = insert(root, 37, "Sweet Potato");
	root = insert(root, 48, "Vitelotte");
	root = insert(root, 77, "Melody Potato");
//	root = insert(root, 99, "Kennebec Potato");
	root = insert(root, 43, "Yukon Gold Potato");
	
	preOrder(root);
	
	printf("\nSearching\n");
	Node *res = search(root, 43);
	if(res != NULL){
		printf("%s\n", res -> name);
	}
	
	printf("\nDelete\n");
	root = remove(root, 48);
	root = remove(root, 37);
	preOrder(root);
	return 0;
}
	
	
