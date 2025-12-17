#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//CHAINING

struct Node{
	char name[51];
	Node *next;
} *head[20];

void pushHead(int index, char name[]){
	Node *curr = (Node*)malloc(sizeof(Node));
	strcpy(curr->name, name);
	curr->next = NULL;
	
	if(head[index] == NULL){
		head[index] = curr;
	}
	else{
		curr->next = head[index];
		head[index] = curr;
	}
}

int hash(char name[]){
	int l = strlen(name);
	int sum = 0;
	for(int i=0;i<l;i++){
		if('A' <= name[i] && name[i] <= 'Z'){
			sum+=name[i] - 'A';
		}
	}
	return sum%20;
}

void push(char name[]){
	int key = hash(name);
	printf("%s %d\n",name,key);
	pushHead(key,name);
}

int main(){
	
	push("KEVIN");
	push("BUDI");
	push("JONO");
	push("ANI");
	push("TONO");
	push("JOKO");
	push("DEO");
	
	printf("%s\n",head[1]->name);
	printf("%s\n",head[1]->next->name);
	
	return 0;
}
