#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int ID;
	char Name[50];
	int priority;
} heap[100];

int n = 1;

int parent(int n){
	return n/2;
}

int leftChild(int n){
	return 2*n;
}

int rightChild(int n){
	return (2*n)+1;
}

void swap(int a, int b){
	Node temp = heap[a];
	heap[a] = heap[b];
	heap[b] = temp;
}

void heapify_up(int n){
	if(n <= 0){
		return;
	}
	int p = parent(n);
	if(heap[n].priority < heap[p].priority){
		swap(n,p);
		heapify_up(p);
	}
}

void heapify_down(int i){
	int left = leftChild(i);
	int right = rightChild(i);
	int small = i;
	
	if(left <= n-1 && heap[left].priority < heap[small].priority){
		small = left;
	}
	if(right <= n-1 && heap[right].priority < heap[small].priority){
		small = right;
	}
	if(small != i){
		swap(i, small);
		heapify_down(small);
	}
}

void insert(Node temp){
	heap[n] = temp;
	heapify_up(n);
	n++;
}

void extract_min(){
	if(n == 1){
		return;
	}
	
	heap[1] = heap[n-1];
	n--;
	heapify_down(1);
}

void peek_min(){
	if(n < 1){
		return;
	}
	
	printf("ID tugas : %d\n",heap[1].ID);
	printf("Nama tugas : %s\n",heap[1].Name);
	printf("Priority ke : %d\n",heap[1].priority);
}

void display(){
	if(n < 1){
		return;
	}
	
	printf("Daftar tugas : \n");
	for(int i=1;i<n;i++){
		printf(" %d  %s  %d\n",heap[i].ID,heap[i].Name,heap[i].priority);
	}
}

int main(){
	
	Node tugas1 = {1, "Fix Bug", 3};
	insert(tugas1);
	
	Node tugas2 = {2, "Deploy to Server", 1};
	insert(tugas2);

	Node tugas3 = {3, "Write Documentation", 5};
	insert(tugas3);

	Node tugas4 = {4, "Code Review", 2};
	insert(tugas4);
	
	display();
	peek_min();
	printf("-------------------------------------------------\n");
	extract_min();
	peek_min();
	printf("-------------------------------------------------\n");
	
	Node tugas5 = {5, "Update Library", 4};
	insert(tugas5);
	display();

//	int choice;
//	do{
//		system("cls");
//		printf("1. Tambah tugas\n");
//		printf("2. Lihat tugas prioritas tertinggi\n");
//		printf("3. Hapus tugas prioritas tertinggi\n");
//		printf("4. Tampilkan semua tugas\n");
//		printf("5. Keluar\n");
//		printf("Pilih menu : ");
//		scanf("%d",&choice);
//		
//		
//		switch(choice){
//			case 1:{
//				struct Node temp;
//				printf("Masukkan ID Tugas      : ");
//	            scanf("%d", &temp.ID);
//	            printf("Masukkan Nama Tugas    : ");
//	            scanf(" %[^\n]", temp.Name); 
//	            printf("Masukkan Prioritas     : ");
//	            scanf("%d", &temp.priority);
//	            
//	            insert(temp);
//				break;
//			}
//	        case 2:
//	        	peek_min();
//	        	break;
//	        case 3:
//	        	extract_min();
//	        	break;
//	        case 4:
//	        	display();
//	        	break;
//	        case 5:
//	        	printf("Thanks You\n");
//	        	break;
//	        default:
//	        	printf("Pilihan tidak valid\n");
//		}
//		printf("\nTekan Enter untuk kembali ke menu...");
//		getchar(); getchar();
//	}while(choice != 5);
	
	return 0;
}
