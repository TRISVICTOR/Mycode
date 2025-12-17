//STACK AND QUEUE

//			STACK			QUEUE
//INSERT		push			enqueue
//DELETE		pop				deque
//
//Stack pushHead popHead (sama) LIFO (last in first out)
//Queue pushHead popTail (berlawanan) FIFO (first in first out)
//
//Stack pushTail popTail
//Queue pushTail popHead
//
//stack -> tumpuk piring
//	  -> shunting yard - mengubah infix menjadi postfix
//	  -> DFS depth first searc h
//queue -> antrian loket
//	  -> BFS breadth first search


//priorityQueue pushMid(sort by priority) popHead

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int priority;
	char name[51];
	Node *prev, *next;
} *Head, *Tail;

Node *createdNode(int priority, char name[]){
	Node *curr = (Node*)malloc(sizeof(Node));
	curr->priority = priority;
	strcpy(curr->name, name);
	curr->next = curr->prev = 0;
	return curr;
}

void pushMid(int priority, char name[]){
	Node *Curr = createdNode(priority, name);
	
	if(Head == NULL){	
		Head = Tail = Curr;
	}
	else if(priority < Head->priority){ //push head
		Curr->next = Head;
		Head->prev = Curr;
		Head = Curr;
	}
	else if(Tail->priority <= priority){ //push tail
		Curr->prev = Tail;
		Tail->next = Curr;
		Tail = Curr;
	}
	else{ //push mid
		Node *pivot = Head;
		while(pivot->priority < priority){
			pivot = pivot->next;
		}
		Curr->prev = pivot->prev;
		Curr->next = pivot;
		pivot->prev->next = Curr;
		pivot->prev = Curr;
	}
}

void View(){
	if(Head == NULL){
		printf("Data Kosong!\n");
	}
	Node *Curr  = Head;
	while(Curr != NULL){
		printf("%d %s\n",Curr->priority,Curr->name);
		Curr = Curr -> next;
	}
}

void popHead(){
	if(Head == NULL){
		printf("Data Kosong\n");
		return;
	}
	else if(Head == Tail){
		free(Head);
		Head = Tail = NULL;
		return;
	}
	
	Node *Curr = Head;
	Head = Head->next;
	free(Curr);
	Head->prev = NULL;
	return;
	
}

void popAll(){
	if(Head == NULL){
		printf("DATA KOSONG\n");
		return;
	}
	while(Head){
		popHead();
	}
	Head=Tail=NULL;
}

int main(){
	
	pushMid(rand() % 100, "Ignatia");
	pushMid(rand() % 100, "Joy");
	pushMid(rand() % 100, "Monica");
	pushMid(rand() % 100, "Nadya");
	pushMid(rand() % 100, "Misca");
	
	View();
	
	popAll();
	
	View();
	
	return 0;
}
