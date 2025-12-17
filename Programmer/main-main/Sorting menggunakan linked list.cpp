#include<stdio.h>
#include<stdlib.h>

struct Node{
	int Number;
	Node *Next;
} *Head, *Tail;

void PushHead(int Num){
	Node *Curr = (Node*)malloc(sizeof(Node));
	Curr -> Number = Num;
	Curr -> Next = NULL;
	if(Head == NULL){
		Head = Curr;
		Tail = Curr;
	}
	else{
		Curr -> Next = Head;
		Head = Curr;
	}
}

void PushTail(int Num){
	Node *Curr = (Node*)malloc(sizeof(Node));
	Curr -> Number = Num;
	Curr -> Next = NULL;
	if(Head == NULL){
		Head = Curr;
		Tail = Curr;
	}
	else{
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
	}else{
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
	
	int tc;
	scanf("%d",&tc);
	
	int Num;
	
	for(int i=0;i<tc;i++){
		scanf("%d",&Num);
		PushHead(Num);
	}
	
	for(int i=0;i<tc;i++){
		scanf("%d",&Num);
		PushTail(Num);
	}

	int berhenti;
	struct Node *angka1;
	struct Node *angka2=NULL;
	
	if(Head != NULL){
		do{
			berhenti=0;
			angka1 = Head;
			
			while(angka1 -> Next != angka2){
				if(angka1 -> Number > angka1 -> Next -> Number){
					int asal = angka1 -> Number;
					angka1 -> Number = angka1 -> Next -> Number;
					angka1 -> Next -> Number = asal;
					berhenti = 1;
				}
				angka1 = angka1 -> Next;
			}
			angka2 = angka1;
		}while(berhenti);
	}
	
	View();
	PopHead();
	printf("\n");
	
	View();
	PopTail();
	printf("\n");
	View();
	printf("\n");
	
	return 0;
}
