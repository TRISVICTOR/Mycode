#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<conio.h>
#define jumlahChar 26

typedef struct Node{
	Node *children[jumlahChar];
	bool terminal;
	char description[255];
} Node;


Node *newnode(){
	Node *curr = (Node*)malloc(sizeof(Node));
	curr->terminal = false;
	curr->description[0] = '\0';
	for(int i = 0;i<jumlahChar;i++){
		curr->children[i] = NULL;
	}
	return curr;
}

void insert(Node **root, char *slang, char *desc){
	if(*root == NULL){
		*root = newnode();
	}
	
	Node *temp = *root;
	
	for(int i = 0;i<strlen(slang);i++){
		if(temp->children[(unsigned char)slang[i]] == NULL){
			temp->children[(unsigned char)slang[i]] = newnode();
		}
		temp = temp->children[(unsigned char)slang[i]];
	}
	
	temp->terminal = true;
	strcpy(temp->description, desc);
}

Node *search(Node *root, char *slang){
	if(root == NULL){
		return NULL;
	}
	
	Node *curr = root;
	
	for(int i = 0;i<strlen(slang);i++){
		if(curr->children[(unsigned char)slang[i]] == NULL){
			return NULL;
		}
		curr = curr->children[(unsigned char)slang[i]];
	}
	return curr->terminal ? curr : NULL;
}

bool validSlang(const char *slang){
	if(strlen(slang) <= 1 || strchr(slang, ' ')){
		return false;
	}
	return true;
}

void printSlangPrefix(Node *root, char *prefix, int level){
	
}

bool validDesc(char *desc){
	int word = 0;
	bool theWord = false;
	
	for(int i = 0;desc[i] != '\0';i++){
		if(desc[i] != ' '){
			if(theWord == false){
				word++;
				theWord = true;
			}
		}
		else{
			theWord = false;
		}
	}
	return word >= 2;
}

int urutan = 1;
void PrintAll(Node *root, char *word, int level){
	if(root->terminal == true){
		word[level] = '\0';
		printf("%d. %s\n",urutan,word);
		urutan++;
	}
	
	for(int i = 0;i<jumlahChar;i++){
		if(root->children[i] != NULL){
			word[level] = (char)i;
			PrintAll(root->children[i],word,level+1);
		}
	}
}

void PrintHeader(Node *root){
	if(root == NULL){
		printf("There is no slang word yet in the dictionary.\n");
		return;
	}
	else{
		printf("List of all slang words in the dictionary:\n");
		char word[125];
		PrintAll(root, word, 0);
	}
}

void Exit(){
	printf("Thank you... Have a nice day :)\n");
	exit(0);
}

int main(){
	
	Node *root = NULL;
	
	int number;
	int choice;
	char word[125];
	char slang[50];
	char desc[255];
	char prefix[255];
	
	
	do{
		system("cls");
		printf("1. Release a new slang word\n");
		printf("2. Search a slang word\n");
		printf("3. View all slang words starting with a certain prefix word\n");
		printf("4. View all slang words\n");
		printf("5. exit\n");
		printf("Input what you want to do : ");
		scanf("%d",&choice);getchar();
		
		switch(choice){
			case 1: {
				do{
					printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
//					fgets(slang, sizeof(slang), stdin);
//    				slang[strcspn(slang, "\n")] = '\0';
    				scanf("%[^\n]", slang); getchar();
				}while(validSlang(slang) == false);
				
				
				
				
				do{
					printf("Input a new slang word description [Must be more than 2 words]: ");
//					fgets(desc, sizeof(desc), stdin);
//					desc[strcspn(desc, "\n")] = '\0';
					scanf("%[^\n]", desc); getchar();
				}while(validDesc(desc) == false);
				
				
//				printf("%s %s", slang, desc);
//				getch();
				
				Node *curr = search(root,slang);
				if(curr){
					strcpy(curr->description, desc);
					printf("\nSuccessfully updated a slang word.\n");
				}
				else{
					insert(&root, slang, desc);
					printf("\nSuccessfully released new slang word.\n");
				}
				break;
			}
			case 2:
				do{
					printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
					fgets(slang, sizeof(slang), stdin);
    				slang[strcspn(slang, "\n")] = '\0';
				}while(validSlang(slang) == false);
				
				
				break;
			case 3:
				printf("Input a prefix to be searched: ");
				fgets(prefix, sizeof(prefix), stdin);
    			prefix[strcspn(prefix, "\n")] = '\0';
				
				break;
			case 4: {
				PrintHeader(root);
				break;
			}
			case 5:
				Exit();
				break;
			default:
				printf("Wrong input, ");
				printf(" input again.");
				break;
		}
		printf("\n\nPress enter to continue...");getchar();
	} while(1);
	
	return 0;
}
