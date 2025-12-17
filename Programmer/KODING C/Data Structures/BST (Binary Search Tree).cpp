#include<stdio.h>
#include<stdlib.h>

struct Node{
	int num;
	Node *left;
	Node *right;
}*root = NULL;

Node *createNode(int num){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode -> num = num;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

Node *insert(Node *root, int num){
	if(root == NULL){
		return createNode(num);
	}
	else if(num < root -> num){
		root -> left = insert(root -> left, num);
	}
	else{
		root -> right = insert(root -> right, num);
	}
	return root;
}

//Node *insert(Node *root, const char *name, int num){
//	if(root == NULL){
//		return createNode(name, num);
//	}
//	if(num < root -> num){
//        root -> left = insert(root -> left, name, num);
//    }
//	else if(num > root -> num){
//        root -> right = insert(root -> right, name, num);
//    }
//	else{ // When the num is same
//        if(strcmp(name, root -> name) < 0){
//            root -> left = insert(root -> left, name, num);
//        }
//		else{
//            root-> right = insert(root -> right, name, num);
//        }
//    }
//    return root;
//}

// InOrder
// 2+3
// LPR

//PreOrder
// +23
// PLR

//PostOrder
// 23+
// LRP

void preOrder(Node *root){
	if(root == NULL){
		return;
	}
	printf("%d ", root -> num);
	preOrder(root -> left);
	preOrder(root -> right);
}

void inOrder(Node *root){
	if(root == NULL){
		return;
	}
	inOrder(root -> left);
	printf("%d ", root -> num);
	inOrder(root -> right);
}

void postOrder(Node *root){
	if(root == NULL){
		return;
	}
	postOrder(root -> left);
	postOrder(root -> right);
	printf("%d ", root -> num);
}

void update(Node *root, int num, int newNum){
	if(root == NULL){
		return;
	}
	update(root -> left, num, newNum);
	if(root -> num == num){
		root -> num = newNum;
		return;
	}
	update(root -> right, num, newNum);
	return;
}

Node *remove(Node *root, int num){
	if(root == NULL){
		return root;
	}
	if(num < root -> num){
		root -> left = remove(root -> left, num);
	}
	else if(num > root -> num){
		root -> right = remove(root -> right, num);
	}
	else{
		// Case 1: 0 Child
		if(root -> left == NULL && root -> right == NULL){
			free(root);
			root = NULL;
			return NULL;
		}
		// Case 2: 1 Child
		else if(root -> left == NULL || root -> right == NULL){
			Node *temp = root -> left ? root -> left : root -> right;
			free(root);
			root = NULL;
			return temp;
		}
		else{
			// Case 3 : 2 Children
			// Find the inorder successor (smallest in the right subtree)
			Node *successor = root -> right;
			while(successor -> left != NULL){
				successor = successor -> left;
			}
			root -> num = successor -> num; // Ganti nilai node dengan nilai successor
			root -> right = remove(root -> right, successor -> num); // Hapus successor
			
//			Node *predecessor = root->left;
//          while (predecessor->right != NULL) {
//              predecessor = predecessor->right;
//          }
//          root->num = predecessor->num;
//          root->left = remove(root->left, predecessor->num);
			
		}
	}
	return root;
}

Node *get_pred(Node *root){
	Node* curr = root -> left;
	while(curr -> right){
		curr = curr -> right;
	}
	return curr;
}

Node* remove2(Node* root, int num){
    if(root == NULL){
        printf("Product not found\n");
        return NULL;
    }
    if(num < root -> num){
        root -> left = remove2(root -> left, num);
    }
    else if(num > root -> num){
        root -> right = remove2(root -> right, num);
    }
    else{
        if(root -> left == NULL || root -> right == NULL){ // 0 child or 1 child
            Node* temp = NULL;
            if(root -> left){
                temp = root -> left;
            }
            else{
                temp = root -> right;
            }
            
            free(root);
            root = temp;
            return root;  
        }
        else{ // 2 children
            Node *pred = get_pred(root);
            root -> num = pred -> num;
            
            
            root -> left = remove2(root -> left, pred -> num);
        }
    }
    return root;
}

Node *search(Node* root, int num){
	if(root == NULL || root -> num == num){
		return root;
	}
	if(num < root -> num){
		return search(root -> left, num);
	}
	return search(root -> right, num);
}

int searchLevel(Node* root, int num, int level) {
    if(root == NULL){
        return NULL;  
    }
    if(num < root -> num){
        return searchLevel(root->left, num, level + 1);
    }
    else if(num > root->num){
        return searchLevel(root->right, num, level + 1);
    }
    else{
        return level;  
    }
}

void deleteTree(Node *node){
    if(node == NULL){
    	return;
	}
    deleteTree(node -> left);
    deleteTree(node -> right);
    free(node);
    node = NULL;
}

int main(){
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 4);
	printf("PreOrder\n");
	preOrder(root);
	
	puts(""); puts("");
	deleteTree(root);
	root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 4);
	printf("Inorder\n");
	inOrder(root);
	
	puts(""); puts("");
	deleteTree(root);
	root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 4);
	printf("Postorder\n");
	postOrder(root);
	
	puts(""); puts("");
	deleteTree(root);
	root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 4);
	update(root, 0, 5);
	printf("Update 0 = 5 (InOrder)\n");
	inOrder(root);

	puts(""); puts("");
	deleteTree(root);
	root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 4);
	root = remove2(root, 3);
	printf("Remove 3 (InOrder)\n");
	inOrder(root);
	
	puts(""); puts("");
	deleteTree(root);
	root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 4);
	Node* result = search(root, 3);
	printf("Search 3\n");
	if(result != NULL){
		printf("A node with a value of 3 has been found\n", result -> num);
	}
	else{
		printf("Not found\n");
	}
	
	puts(""); 
	deleteTree(root);
	root = NULL;
	root = insert(root, 2);
	root = insert(root, 1);
	root = insert(root, 3);
	root = insert(root, 0);
	root = insert(root, 4);
//	       2 (Level 0)
//      / \
//    1 (Level 1)  3 (Level 1)
//   /            / \
//  0 (Level 2)  N   4 (Level 2)
	int searchResult = searchLevel(root, 4, 0);
	if(searchResult == -1){
    	printf("Search not found.\n");
	}else{
    	printf("Search result: %d\n", searchResult);
	}
	
	
//	puts(""); puts("");
//	deleteAll();
//	printf("After delete\n");
//	inOrder(root);
//	printf("NULL\n");
	
	
	return 0;
}
