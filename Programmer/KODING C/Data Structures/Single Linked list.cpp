//linked list = sekumpulan data yang sejenis, tapi sifatnya dinamis
//dinamis di linked list = sizenya akan mengikuti kebutuhan
//kelemahan linked list = aksesnya lambat dimana linked list O(n), sedangkan akses array O(1)
//hal yang penting di linked list = data dan link

//single linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
	//data
	int Number;
	//link -> dalam bentuk pointer
	Node *Next;
} *Head, *Tail;

void PushHead(int Num){
	Node *Curr = (Node*)malloc(sizeof(Node));
	Curr -> Number = Num;
	Curr -> Next = NULL;
	if(Head == NULL){	//kalau kosong
		Head = Curr;
		Tail = Curr;
	}
	else{	//kalau udah ada
		Curr -> Next = Head;
		Head = Curr;
	}
}

void PushTail(int Num){
	Node *Curr = (Node*)malloc(sizeof(Node));
	Curr -> Number = Num;
	Curr -> Next = NULL;
	if(Head == NULL){	//kalau kosong
		Head = Curr;
		Tail = Curr;
	}
	else{	//kalau udah ada
		Tail -> Next = Curr;
		Tail = Curr;
	}
}

void View(){
	Node *Curr  = Head;
	while(Curr != NULL){
		printf("%d ",Curr -> Number);
		Curr = Curr -> Next;
	}
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
		Node *Curr = Head;
		while(Curr -> Next != Tail){
			Curr = Curr -> Next;
		}
		free(Tail);
		Tail = Curr;
		Tail -> Next = NULL;
	}
}

int main(){
	
	PushHead(2);
	PushHead(37);
	PushHead(28);
	
	PushTail(5);
	
	View();
	printf("\n");
	PopHead();
	
	View();
	printf("\n");
	PopTail();
	
	View();
	printf("\n");
	
//	printf("Head : %d\n",Head -> Number);
//	printf("Head Next : %d\n",Head -> Next -> Number);
//	printf("Head Next Next : %d\n",Head -> Next -> Next -> Number);
//	printf("Head Next Next Next : %d\n",Head -> Next -> Next -> Next -> Number);
//	printf("Tail : %d\n",Tail -> Number);
	
	return 0;
}
