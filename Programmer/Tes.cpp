//Create a program based on the class' exercise with additional menu:
//1. View Data
//2. Add Data
//3. Delete Data
//4. Exit
//
//struct address ada street names, postal code, number
//struct data ada ID, name, score

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct adrs{
	char NamaJalan[50];
	int PostalCode;
	int NomorPonsel;
};

struct data{
	int ID;
	char Nama[50];
	float Nilai;
	struct adrs Address;
};

struct data *murid=NULL;
int jumlah = 0;

void ViewData(){
	if(jumlah == 0){
		printf("Belum ada data murid\n");
		printf("Silakan masukkan data murid\n");
		return;
	}
	
	printf("============================== Data Murid ==============================\n");
	printf("\tNama\t\tID\t\tNilai\t\tNama Jalan\t\tPostal Code\t\tNomor Ponsel\n");
	for(int i=0;i<jumlah;i++){
		printf("\t%s\t\t%d\t\t%f\t\t%s\t\t%d\t\t%d\n",murid[i].Nama,murid[i].ID,murid[i].Nilai,murid[i].Address.NamaJalan,murid[i].Address.PostalCode,murid[i].Address.NomorPonsel);
		printf("------------------------------------------------------------------------------\n");
	}
}

void AddData(){
	jumlah++;
	struct data *temp = (struct data *)realloc(murid,jumlah * sizeof(struct data));
	murid = temp;
	
	printf("Masukkan Nama : ");
	fgets(murid[jumlah-1].Nama,50,stdin);
	murid[jumlah-1].Nama[strcspn(murid[jumlah-1].Nama,"\n")] = '\0';
	
	printf("Masukkan ID : ");
	scanf("%d",&murid[jumlah-1].ID);
	getchar();
	
	printf("Masukkan Nilai : ");
	scanf("%f",&murid[jumlah-1].Nilai);
	getchar();
	
	printf("Masukkan Nama Jalan : ");
	fgets(murid[jumlah-1].Address.NamaJalan,50,stdin);
	murid[jumlah-1].Address.NamaJalan[strcspn(murid[jumlah-1].Address.NamaJalan,"\n")] = '\0';
	
	printf("Masukkan Postal Code : ");
	scanf("%d",&murid[jumlah-1].Address.PostalCode);
	getchar();
	
	printf("Masukkan Nomor Ponsel : ");
	scanf("%d",&murid[jumlah-1].Address.NomorPonsel);
	getchar();
	
	printf("Data Berhasil Di Masukkan\n");
}

void DeleteData(){
	if(jumlah == 0){
		printf("Belum ada data murid\n");
		printf("Silakan masukkan data murid\n");
		return;
	}
	
	char nama[50];
	int index=-1;
	printf("Masukkan murid yang ingin anda hapus datanya : ");
	fgets(nama,sizeof(nama),stdin);
	nama[strcspn(nama,"\n")] = '\0';
	
	for(int i=0;i<jumlah;i++){
		if(strcmp(murid[i].Nama,nama)==0){
			index = i;
			break;
		}
	}
	
	if (index == -1){
        printf("Murid dengan nama %s tidak ditemukan!\n",nama);
        return;
	}
	
	for(int i=index;i<jumlah-1;i++){
		murid[i]=murid[i+1];
	}
	
	jumlah--;
	struct data *temp = (struct data *)realloc(murid, jumlah * sizeof(struct data));
	
	if(temp == NULL && jumlah > 0){
		printf("Gagal mengalokasikan memori setelah penghapusan!\n");
        return;
	}
	
	murid = temp;
	
	printf("Data Berhasil Dihapus\n");
}

int main(){
	
	int pilihan;
	do{
		printf("Data Kegiatan Kelas Murid\n");
		printf("1. View Data\n");
		printf("2. Add Data\n");
		printf("3. Delete Data\n");
		printf("4. Exit\n");
	
		printf("Masukkan Pilihan : ");
		scanf("%d",&pilihan);getchar();
		
		switch(pilihan){
			case 1:
				system("cls");
				printf("\n");
				ViewData();
				printf("\n");
				break;
			case 2:
				system("cls");
				AddData();
				system("cls");
				break;
			case 3:
				system("cls");
				DeleteData();
				system("cls");
				break;
			case 4:
				system("cls");
				printf("Terima Kasih\n");
				exit(0);
				break;
			default:
				system("cls");
				printf("Ga ada pilihannya.\n");
				printf("Pilih lah yang sesuai.\n\n");
				break;
		}
		printf("Press Enter To Continue...");getchar();
		system("cls");
	}while(pilihan != 4);
	
	return 0;
}
