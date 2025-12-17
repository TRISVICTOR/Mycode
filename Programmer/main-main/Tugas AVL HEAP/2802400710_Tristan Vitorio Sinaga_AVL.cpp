#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int ID;
	char name[100];
	int stock;
	int height;
	Node *left, *right;
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

Node *push(Node *curr, int ID, char name[], int stock){
	if(curr == NULL){
		curr = (Node*)malloc(sizeof(Node));
		curr->height = 1;
		curr->ID = ID;
		curr->left = curr->right = NULL;
		strcpy(curr->name,name);
		curr->stock = stock;
	}
	else{
		if(ID == curr->ID){
			printf("Duplicate\n");
			return 0;
		}
		else if(ID < curr->ID){
			curr->left = push(curr->left,ID,name,stock);
		}
		else{
			curr->right = push(curr->right,ID,name,stock);
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

Node *pop(Node *curr, int ID){
	if(curr == NULL){
		printf("Barang tidak ditemukan\n");
		return 0;
	}
	else{
		if(ID == curr->ID){
			if(curr->left == NULL && curr->right == NULL){
				free(curr);
				return 0;
			}
			else if(curr->left != NULL && curr->right != NULL){
				Node *temp = rightMost(curr->left);
				curr->ID = temp->ID;
				curr->stock = temp->stock;
				strcpy(curr->name,temp->name);
				curr->left = pop(curr->left,temp->ID);
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
		else if(ID < curr->ID){
			curr->left = pop(curr->left,ID);
		}
		else{
			curr->right = pop(curr->right,ID);
		}
	}
	return rebalance(curr);
}

Node *search(Node *curr,int ID){
	if(curr == NULL){
		printf("Barang tidak ditemukan\n");
		return 0;
	}
	else{
		if(ID == curr->ID){
			printf("Berhasil ditemukan : %d %s %d\n",curr->ID,curr->name,curr->stock);
			return curr;
		}
		else if(ID < curr->ID){
			return search(curr->left,ID);
		}
		else{
			return search(curr->right,ID);
		}
	}
}

Node *inorder(Node *curr){
	if(curr != NULL){
		inorder(curr->left);
		printf("%d %s %d\n",curr->ID,curr->name,curr->stock);
		inorder(curr->right);
	}
}

int main(){
	
	root = push(root,20, "Mouse", 50);
	root = push(root,10, "Keyboard", 30);
	root = push(root,30, "Monitor", 20);
	root = push(root,25, "Webcam", 15);
	root = push(root,40, "Laptop", 10);
	
	root = pop(root, 10);
	
	search(root, 25);
	
	inorder(root);
	
//	int tc;
//	scanf("%d",&tc);getchar();
//	for(int i=0;i<tc;i++){
//		char choose;
//		scanf(" %c",&choose);getchar();
//		
//		if(choose > 'a' && choose < 'z'){
//			choose -= 32;
//		}
//		
//		if(choose == 'I'){
//			char name[100];
//			int ID;
//			int stock;
//			scanf("(%d, \"%[^\"]\", %d)",&ID,name,&stock);getchar();
//			root = push(root, ID, name, stock);	
//		}
//		else if(choose == 'E'){
//			int deleteID;
//			scanf("%d",&deleteID);getchar();
//			root = pop(root,deleteID);
//		}
//		else if(choose == 'S'){
//			int find;
//			scanf("%d",&find);getchar();
//			search(root, find);
//		}
//		else if(choose == 'T'){
//			inorder(root);
//		}
//	}
	
	return 0;
}
