#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int num;
	Node *left;
	Node *right;
	int height;
} *root;

int getHeight(Node *curr){
	if(curr != NULL){
		return curr->height;
	}
	return 0;
}

int max(int a, int b){
	return a > b ? a : b;
}

int getBalance(Node *curr){
	if(curr != NULL){
		return getHeight(curr->left)-getHeight(curr->right);
	}
	return 0;
}

Node *leftRotate(Node *curr){
	Node *x = curr->right;
	Node *T2 = x->left;
	
	x->left = curr;
	curr->right = T2;
	
	curr->height = max(getHeight(curr->left),getHeight(curr->right)) + 1;
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	
	return x;
}

Node *rightRotate(Node *curr){
	Node *x = curr->left;
	Node *T2 = x->right;
	
	x->right = curr;
	curr->left = T2;
	
	curr->height = max(getHeight(curr->left),getHeight(curr->right)) + 1;
	x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
	
	return x;
}

Node *rebalance(Node *curr){
	if(curr == NULL){
		return curr;
	}
	curr->height = max(getHeight(curr->left),getHeight(curr->right)) + 1;
	int b = getBalance(curr);
	
	if(b > 1){
		if(getBalance(curr->left) < 0){
			curr->left = leftRotate(curr->left);
		}
		curr = rightRotate(curr);
	}
	else if(b < -1){
		if(getBalance(curr->right) > 0){
			curr->right = rightRotate(curr->right);
		}
		curr = leftRotate(curr);
	}
	return curr;
}

Node *insert(Node *curr, int num){
	if(curr == NULL){
		curr = (Node*)malloc(sizeof(Node));
		curr->height = 1;
		curr->left = curr->right = NULL;
		curr->num = num;
	}
	else{
		if(num == curr->num){
			printf("Duplicate\n");
		}
		else if(num < curr->num){
			curr->left = insert(curr->left, num);
		}
		else if(num > curr->num){
			curr->right = insert(curr->right, num);
		}
	}
	return rebalance(curr);
}

Node *rightMost(Node *curr){
	if(curr->right != NULL){
		return rightMost(curr->right);
	}
	return curr;
}

Node *pop(Node *curr, int num){
	if(curr == NULL){
		printf("Tidak ada\n");
		return curr;
	}
	else{
		if(num == curr->num){
			if(curr->left == NULL && curr->right == NULL){
				free(curr);
				return 0;
			}
			else if(curr->left != NULL && curr->right != NULL){
				Node *temp = rightMost(curr->left);
				curr->num = temp->num;
				curr->left = pop(curr->left, temp->num);
			}
			else{
				Node *temp = curr->left;
				if(curr->right != NULL){
					temp = curr->right;
				}
				free(curr);
				curr = temp;
			}
		}
		else if(num < curr->num){
			curr->left = pop(curr->left, num);
		}
		else if(num > curr->num){
			curr->right = pop(curr->right, num);
		}
	}
	return rebalance(curr);
}

Node *search(Node *curr, int num){
	if(curr == NULL){
		printf("Tidak ditemukan\n");
		return 0;
	}
	else{
		if(num == curr->num){
			printf("%d\n",curr->num);
			return curr;
		}
		else if(num < curr->num){
			return search(curr->left, num);
		}
		else if(num > curr->num){
			return search(curr->right, num);
		}
	}
}

void inorder(Node *curr){
	if(curr != NULL){
		inorder(curr->left);
		printf("%d\n",curr->num);
		inorder(curr->right);
	}
}

int main(){
	
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 70);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 60);
	root = insert(root, 80);

	printf("Inorder setelah insert:\n");
	inorder(root);
	printf("------------\n");

	// SEARCH
	printf("Search 60:\n");
	search(root, 60); // Ada
	printf("Search 100:\n");
	search(root, 100); // Tidak ditemukan
	printf("------------\n");

	// DELETE
	root = pop(root, 70); // delete node dengan dua child
	root = pop(root, 20); // delete node daun (leaf)
	root = pop(root, 30); // delete node dengan satu child

	printf("Inorder setelah delete:\n");
	inorder(root);
	printf("------------\n");
	
	return 0;
}
