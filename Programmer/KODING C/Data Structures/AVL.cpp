#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int num;
	char name[101];
	int height;
	Node *left, *right;
} *root;

int getHeight(Node *curr){
	if(curr == NULL){
		return 0;
	}
	return curr->height;
}

int max(int a, int b){
	return a > b ? a : b;
}

int getBalance(Node *curr){
	if(curr != NULL){
		return getHeight(curr->left) - getHeight(curr->right);
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
		return 0;
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

Node *push(Node *curr, int num, char name[]){
	if(curr == NULL){
		curr = (Node*)malloc(sizeof(Node));
		curr->height = 1;
		curr->left = curr->right = NULL;
		curr->num = num;
		strcpy(curr->name,name);
	}
	else{
		if(curr->num < num){
			curr->right = push(curr->right, num, name);
		}
		else if(curr->num > num){
			curr->left = push(curr->left, num, name);
		}
		else{
			printf("Duplicate insert ignored: %d\n", num);
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
		printf("Tidak ditemukan\n");
		return 0;
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
				strcpy(curr->name, temp->name);
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

void inorder(Node *curr){ //LMR
	if(curr != NULL){
		inorder(curr->left);
		printf("%d %s\n",curr->num, curr->name);
		inorder(curr->right);
	}
}

void preorder(Node *curr){ //LMR
	if(curr != NULL){
		printf("%d %s\n",curr->num, curr->name);
		preorder(curr->left);
		preorder(curr->right);
	}
}

void postorder(Node *curr){ //LMR
	if(curr != NULL){
		postorder(curr->left);
		postorder(curr->right);
		printf("%d %s\n",curr->num, curr->name);
	}
}

Node *printMinVal(Node *curr){
	while(curr->left != NULL){
		curr = curr->left;
	}
	printf("%d %s\n",curr->num, curr->name);
}

Node *deleteMin(Node *curr){
	if(curr == NULL){
		return NULL;
	}
	
	if(curr->left == NULL){
		return curr->right;
	}
	
	curr->left = deleteMin(curr->left);
	return rebalance(curr);
}

Node *search(Node *curr, int num){
	if(curr == NULL){
		printf("Ga ada disini\n");
		return 0;
	}
	else{
		if(num == curr->num){
			printf("ada nih %d %s\n",curr->num, curr->name);
			return curr;
		}
		else if(num > curr->num){
			curr->right = search(curr->right, num);
		}
		else if(num < curr->num){
			curr->left = search(curr->left, num);
		}
	}
}

void printTree(Node *curr, int level=1) {
    if (curr == NULL) {
        return;
    }
    printTree(curr->right, level + 1);
    for (int i = 0; i < level; i++) {
        printf("   ");
    }
    printf("%d\n", curr->num);
    printTree(curr->left, level + 1);
}


int main(){
	
	root = push(root,20, "Mouse");
	root = push(root,10, "Keyboard");
	root = push(root,30, "Monitor");
	root = push(root,25, "Webcam");
	root = push(root,40, "Laptop");
	
	inorder(root);
	printf("----------------\n");
	preorder(root);
	printf("----------------\n");
	postorder(root);
	printf("----------------\n");
	
	root = pop(root, 10);
	
	inorder(root);
	printf("----------------\n");
	
	search(root, 25);
	printf("----------------\n");
	
	printMinVal(root);
	printf("----------------\n");
	
	root = deleteMin(root);
	inorder(root);
	printf("----------------\n");
	
	printTree(root);
	
	return 0;
}
