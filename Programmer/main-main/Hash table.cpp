#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
	char nim[11];
	char name[101];
	int semester;
	Student *next;
};

Student *student[13]={NULL};

Student *createStudent(const char *nim, const char *name, int semester){
	Student *newStudent = (Student*)malloc(sizeof(Student));
	strcpy(newStudent->name,name);
	strcpy(newStudent->nim,nim);
	newStudent->semester=semester;
	newStudent->next=NULL;
	return newStudent;
}

int hash(const char*nim){
	int sum = 0;
	int len = strlen(nim);
	for(int i=0;i<strlen(nim);i++){
		sum+=nim[i];
	}
	return sum%13;
}

void insert(const char *nim, const char *name, int semester){
	
}

void printAll(){
	for(int i=0;i<13;i++){
		printf("IDX %d : ",i);
		Student *curr=student[i];
		while(curr!=Null){
			printf("%s %s %d ->",curr->nim,curr->name,curr->semester);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

void remove(const char*nim){
	int idx = hash(nim);
	Student *curr=student[idx];
	Student *prev=NULL;
	while(curr!=NULL && strcmp(curr->nim,nim)!=0){
		prev=curr;
		curr=curr->next;
	}
	if(curr!=NULL){
		if(prev == NULL){
			
		}
	}
}

int main(){
	
	
	
	return 0;
}
