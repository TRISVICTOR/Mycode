#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<ctype.h>
#include<unistd.h>

int totalCus = 0;



struct Customer{
	char name[100];
	double height;
	int weight;
}c[1000];

Customer createCustomer(const char *name, double height, int weight){
	Customer temp;
	strcpy(temp.name, name);
	temp.height = height;
	temp.weight = weight;
	return temp;
}

void printAll(Customer *c, int count){
	printf("No Name                Height Weight\n");
	for(int i = 0; i < count; i++){
		 printf("%-2d %-20s %-6.2lf %d\n", i + 1, c[i].name, c[i].height, c[i].weight);
	}
	
}

void insertData();
void updateData();
void sortingData();
void createBMIReport();
void exit();

void mainMenu(){
	int choice;
	do{
		system("cls");
		printAll(c, totalCus);
		puts(""); puts("");
		printf("Health and Fit Clinic\n");
		printf("========================\n");	
		printf("[1] Insert Data\n");	
		printf("[2] Update Data\n");	
		printf("[3] Sorting Data\n");	
		printf("[4] Create BMI Report\n");	
		printf("[5] Exit\n");
		printf("Your choice: ");
		
		
		scanf("%d", &choice); getchar();
	}while(!(choice >= 1 && choice <= 5));
	
	switch(choice){
		case 1:{
			insertData();	
			break;
		}
		case 2:{
			system("cls");
    		printAll(c, totalCus); 
			updateData();
			break;
		}
		case 3:{
			sortingData();
			break;
		}
		case 4:{
			createBMIReport();
			break;
		}
		case 5:{
			exit();
			exit(0);
			break;
		}
	}
	
}


bool isEmpty(char* name){
	for(int i = 0; i<strlen(name); i++){
		if(!isspace(name[i])){
			return true;
		}
	}
	return false;
}

void trim(char* word){
	int j = 0;
	int len = strlen(word);
	int begin = 0;
	int ending = len - 1;
	while(begin < len && isspace(word[begin])){
		begin++;
	}
	while(ending >= begin && isspace(word[ending])){
		ending--;
	}
	for(int i = begin; i<=ending; i++){
		
		word[j++] = word[i];
		
	}
	
	word[j] = '\0';
}


void insertData(){
	system("cls");
	printAll(c, totalCus); puts("");
	
	char cusName[100];
    bool space = false;
    do{
        printf("Insert New Name: ");
        cusName[0] = '\0';
        scanf("%[^\n]", cusName); getchar(); 

        space = isEmpty(cusName);
        if(strlen(cusName) == 0 || !space){
            printf("Name cannot be empty\n");
            
        }

    }while(strlen(cusName) == 0 || !space); 
    
    trim(cusName);
    
    double cusHeight;
    do{
        printf("Insert New Height: ");
        scanf("%lf", &cusHeight); getchar();
        if(!(cusHeight >= 1 && cusHeight <= 2)){
            printf("Height must be between 1.00 and 2.00\n");
        }
    }while(!(cusHeight >= 1 && cusHeight <= 2));
    
    int cusWeight;
    do{
        printf("Insert New Weight: ");
        scanf("%d", &cusWeight); getchar();
        if(!(cusWeight >= 40 && cusWeight <= 120)){
            printf("Weight must be between 40 and 120\n");
        }
    }while(!(cusWeight >= 40 && cusWeight <= 120));
    

    c[totalCus++] = createCustomer(cusName, cusHeight, cusWeight);
	printf("\nCustomer has been successfully added!\n");
	printf("Press enter to return...\n");
	getch();
	
	mainMenu();
}

void updateData() {
    
    puts("");

    char query[100];
    bool space = false;
    do{
        printf("Insert Search Query [Name]: ");
        query[0] = '\0';
        scanf("%[^\n]", query); getchar(); 

        space = isEmpty(query);
        if(strlen(query) == 0 || !space){
            printf("Name cannot be empty\n");
            
        }

    }while(strlen(query) == 0 || !space); 
	
	trim(query);
	
    bool found = false;
    for(int i = 0; i < totalCus; i++){
        if(strcmp(c[i].name, query) == 0){
            found = true;

            printf("\nInsert New Name: ");
            scanf(" %[^\n]", c[i].name);

            do{
                printf("Insert New Height: ");
                scanf("%lf", &c[i].height);
                if(!(c[i].height >= 1 && c[i].height <= 2)){
                    printf("Height must be between 1.00 and 2.00\n");
                }
            }while(!(c[i].height >= 1 && c[i].height <= 2));

            do{
                printf("Insert New Weight: ");
                scanf("%d", &c[i].weight);
                if(!(c[i].weight >= 40 && c[i].weight <= 120)){
                    printf("Weight must be between 40 and 120\n");
                }
            }while(!(c[i].weight >= 40 && c[i].weight <= 120));

            printf("\nCustomer data successfully updated!\n");
            break;
        }
    }

    if(!found){
        printf("Your query \"%s\" result nothing. Please use a different query.\n", query);
    	getch();
		updateData();
	}
    
    printf("Press enter to return...\n");
	getch();
	
	mainMenu();
}

void nameAscending();
void weightDescending();

void sortingData(){
	system("cls");
    printAll(c, totalCus); 
    puts("");
    
    int choice;
    do{
    	printf("Sorting Order:\n");
    	printf("1. Name Ascending\n");
    	printf("2. Weight Descending\n");
    	printf("Your choice: ");
    	scanf("%d", &choice); getchar();
	}while(!(choice >= 1 && choice <= 2));
    
    switch(choice){
    	case 1:{
    		nameAscending();
			break;
		}
		case 2:{
			weightDescending();
			break;
		}
	}
    
    printf("Press enter to return...\n");
	getch();
	mainMenu();
}

void nameAscending(){
	system("cls");
	for(int i = 0; i < totalCus - 1; i++){
		for(int j = i + 1; j < totalCus; j++){
			if(strcmp(c[i].name, c[j].name) > 0){
				Customer temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
	printAll(c, totalCus);
	printf("\nPress enter to return...\n");
	getch();
	mainMenu();
}

void weightDescending(){
	system("cls");
	for(int i = 0; i < totalCus - 1; i++){
		for(int j = i + 1; j < totalCus; j++){
			if(c[i].weight < c[j].weight){
				Customer temp = c[i];
				c[i] = c[j];
				c[j] = temp;
			}
		}
	}
	printAll(c, totalCus);
	printf("\nPress enter to return...\n");
	getch();
	mainMenu();
}


void printBMI(Customer *c, int count);
void createBMIReport(){
	system("cls");
    printBMI(c, totalCus);
    printf("\nPress enter to return...\n");
    getch();
    mainMenu();
}

void printBMI(Customer *c, int count){
	printf("No Name                 BMI     Classification\n");
    for(int i = 0; i < count; i++){
        double bmi = c[i].weight / (c[i].height * c[i].height);
        char classification[100];
        if(bmi < 18.5){
        	strcpy(classification, "Underweight");

        }
		else if(bmi <= 24.9){
			strcpy(classification, "Normal Weight");

        }
		else if(bmi <= 29.9){
			strcpy(classification, "Overweight");

        }
		else{
			strcpy(classification, "Obese");

        }
        printf("%-2d %-20s %-6.2lf %-15s\n", i + 1, c[i].name, bmi, classification);
    }
}

void deleteData() {
    system("cls");
    printAll(c, totalCus); 
    puts("");

    char query[100];
    bool space = false;
    do{
        printf("Insert Name to Delete: ");
        query[0] = '\0';
        scanf("%[^\n]", query); getchar(); 

        space = isEmpty(query);
        if(strlen(query) == 0 || !space){
            printf("Name cannot be empty\n");
        }

    }while(strlen(query) == 0 || !space); 

    trim(query);

    bool found = false;
    for(int i = 0; i < totalCus; i++){
        if(strcmp(c[i].name, query) == 0){
            found = true;
            // Shift all customers after the deleted one to the left
            for(int j = i; j < totalCus - 1; j++){
                c[j] = c[j + 1];
            }
            totalCus--;  // Decrease the customer count
            printf("\nCustomer \"%s\" has been successfully deleted!\n", query);
            break;
        }
    }

    if(!found){
        printf("Customer \"%s\" not found.\n", query);
    }

    printf("Press enter to return...\n");
    getch();
    mainMenu();
}

void exit(){
	system("cls");
    printf("                                                                  \n"); usleep(50000); //delay 0.05 dtk
    printf("                  Exiting the program. Goodbye!                   \n"); usleep(50000); system("echo \033[33m");
    printf("                                                                  \n"); usleep(50000);
    printf("                 **********           **********                  \n"); usleep(50000);
    printf("              ***************       ***************               \n"); usleep(50000);
    printf("           ********************   ********************            \n"); usleep(50000);
    printf("         ***********************************************          \n"); usleep(50000);
    printf("        *************************************************         \n"); usleep(50000);
    printf("        *************************************************         \n"); usleep(50000);
    printf("         ***********************************************          \n"); usleep(50000);
    printf("          *********************************************           \n"); usleep(50000);
    printf("            *****************************************             \n"); usleep(50000);
    printf("              *************************************               \n"); usleep(50000);
    printf("                *********************************                 \n"); usleep(50000);
    printf("                  *****************************                   \n"); usleep(50000);
    printf("                    *************************                     \n"); usleep(50000);
    printf("                      *********************                       \n"); usleep(50000);
    printf("                        *****************                         \n"); usleep(50000);
    printf("                          *************                           \n"); usleep(50000);
    printf("                            *********                             \n"); usleep(50000);
    printf("                              *****                               \n"); usleep(50000);
    printf("                               ***                                \n"); usleep(50000);
    printf("                                *                                 \n"); usleep(50000); system("echo \033[0m");
    printf("\n");
    printf("			     Lop yu\n");
}


int main(){
	
	c[totalCus++] = createCustomer("Alzriet Gentleheart", 1.76, 67);
	c[totalCus++] = createCustomer("Chelby Adorable", 1.56, 112);
	c[totalCus++] = createCustomer("Gravys Powerful", 1.50, 41);
	c[totalCus++] = createCustomer("Fremranth Dark", 1.39, 56);
	c[totalCus++] = createCustomer("Chulrerth Warm", 1.63, 113);
	c[totalCus++] = createCustomer("Cedyrug Redeemer", 1.65, 76);
	c[totalCus++] = createCustomer("Zemusde Voiceless", 1.69, 68);
	c[totalCus++] = createCustomer("Myrderram Mammoth", 1.85, 54);
	
	mainMenu();
	
	return 0;
}
