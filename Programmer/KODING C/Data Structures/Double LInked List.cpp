//Double Linked List
//PushMid, POpMid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char Nim[11];
	char Nama[51];
	Node *Next;
	Node *Prev;
} *Head, *Tail;

void PushHead(char Nim[], char Nama[]){
	Node *Curr = (Node*)malloc(sizeof(Node));
	
	strcpy(Curr -> Nim, Nim);
	strcpy(Curr -> Nama, Nama);
	Curr -> Next = Curr -> Prev = 0;
	if(Head = 0){
		Head = Tail = Curr;
	}
	else{
		Curr -> Next = Head;
		Head -> Prev = Curr;
		Head = Curr;
	}
}

void PushTail(char Nim[], char Nama[]){
	Node *Curr = (Node*)malloc(sizeof(Node));
	
	strcpy(Curr -> Nim, Nim);
	strcpy(Curr -> Nama, Nama);
	Curr -> Next = Curr -> Prev = 0;
	if(Head = 0){
		Head = Tail = Curr;
	}
	else{
		Curr -> Prev = Tail;
		Tail -> Next = Curr;
		Tail = Curr;
	}
}

void ViewHead(){
	Node *Curr  = Head;
	while(Curr != NULL){
		printf("%s ",Curr -> Nama);
		Curr = Curr -> Next;
	}
	printf("\n");
}

void ViewTail(){
	Node *Curr = Tail;
	while(Curr != NULL){
		printf("%s ",Curr -> Nama);
		Curr = Curr -> Prev;
	}
	printf("\n");
}

void PopHead(){
	if(Head == NULL){
		printf("Data Kosong!\n");
	}
	else if(Head == Tail){
		free(Head);
		Head = NULL;
		Tail = NULL;
	}
	else{
		Node *Curr = Head;
		Head = Head -> Next;
		free(Curr);
		Head -> Prev = NULL;
	}
}

void PopTail(){
	if(Head == NULL){
		printf("Data Kosong!\n");
	}
	else if(Head == Tail){
		free(Head);
		Head = NULL;
		Tail = NULL;
	}
	else{
		Node *Curr = Tail;
		Tail = Tail -> Prev;
		free(Curr);
		Tail -> Next = NULL;
	}
}

void PopAll(){
	while(Head != NULL){
		PopHead();
	}
}

void PushByIndex(int index, char Nim[], char Nama[]){
	if(index == 0){
		PushHead(Nim, Nama);
	}
	else{
		Node *Curr = Head;
		int i = 0;
		while(i < index-1 && Curr != 0){
			Curr = Curr -> Next;
		}
		if(Curr == 0 || Curr -> Next == 0){
			PushTail(Nim, Nama);
		}
		else{
			Node *NewNode = (Node*)malloc(sizeof(Node));
			strcpy(NewNode -> Nim, Nim);
			strcpy(NewNode -> Nama, Nama);
			
			NewNode -> Prev = Curr;
			NewNode -> Next = Curr -> Next;
			Curr -> Next -> Prev = NewNode;
			Curr -> Next = NewNode;
		} 
	}
}

int main(){
	
	
	
	ViewHead();
	ViewTail();
	
	return 0;
}
