#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int ID;
	char name[31];
	char deadline[31];
	Node *prev;
	Node *next;
} *head, *tail;

int taskCount = 0;

void pushMid(char name[], char deadline[]){
	Node *curr = (Node*)malloc(sizeof(Node));
	strcpy(curr->deadline, deadline);
	strcpy(curr->name, name);
	curr->ID = ++taskCount;
	curr->next = NULL;
	curr->prev = NULL;
	
	if(head == NULL){
		head = tail = curr;
	}
	else if(strcmp(curr->deadline,head->deadline) < 0){
		curr->next = head;
		head->prev = curr;
		head = curr;
	}
	else if(strcmp(curr->deadline,tail->deadline) > 0){
		tail->next = curr;
		curr->prev = tail;
		tail = curr;
	}
	else{
		Node *temp = head->next;
		while(strcmp(curr->deadline,temp->deadline) > 0){
			temp = temp->next;
		}
		Node *data = temp->prev;
		data->next = curr;
		temp->prev = curr;
		curr->next = temp;
		curr->prev = data;
	}
}

void finishTask(){
	Node *curr = head;
	if(curr == NULL){
		printf("Belum ada tugas\n");
		return;
	}
	else{
		head = head->next;
		head->prev = NULL;
		free(curr);
	}
}

void popByID(int ID){
	Node *curr = head;
	if (!curr){
        printf("id %d does not exist!\n",&ID);
        return;
    }
    while(ID != curr->ID){
    	curr = curr->next;
	}
    if(curr == head){
    	head = head->next;
    	head->prev = NULL;
    	free(curr);
	}
	else if(curr == tail){
		tail = tail->prev;
		tail->next = NULL;
		free(curr);
	}
}

void print(){
	Node *curr = head;
	while(curr != NULL){
		printf("deadline: %s\n", curr->deadline);
        printf("task name: %s\n", curr->name);
        printf("id: %d\n", curr->ID);
        printf("================================\n");
        curr = curr->next;
	}
}

int main(){
	
	int N,M;
	scanf("%d %d",&N,&M);getchar();
	int ID;
	
	for(int i=0;i<N;i++){
		char deadline[31], name[31];
		scanf("%s %[^\n]",&deadline,&name);
		pushMid(deadline,name);
	}
	
	for(int i=0;i<M;i++){
		
	}
	
	print();
	
	return 0;
}
