#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//struct tanggal{
//	int hari;
//	int bulan;
//	int tahun;
//} today;
//
//struct mahasiswa{
//	char nama[50];
//	char nim[11];
//	tanggal dob;
//	int semester;
//};

int main(){
	
//	struct tanggal ultah;
//	ultah.bulan=1;
//	ultah.hari=9;
//	ultah.tahun=2006;
//	
//	printf("%d %d %d\n",ultah.hari,ultah.bulan,ultah.tahun);
//	
//	mahasiswa deovan;
//	strcpy(deovan.nama,"Deovan Zoe");
//	strcpy(deovan.nim,"2802413083");
//	deovan.dob.hari=23;
//	deovan.dob.bulan=10;
//	deovan.dob.tahun=2006;
//	deovan.semester=2;
//	
//	mahasiswa charis = {
//		"Charis Surijakko",
//		"2802500676",
//		{3,6,2006},
//		2
//	};
//	
//	char namabulan[15][20] = {"Jan","Feb","Mar","Apr","Mei","Jun","Jul","Agus","Sep","Oct","Nov","Dec"};
//	
//	printf("Nama : %s\n",charis.nama);
//	printf("NIM : %s\n",charis.nim);
//	printf("Semester : %d\n",charis.semester);
//	printf("%d %s %d\n",charis.dob.hari,namabulan[charis.dob.bulan-1],charis.dob.tahun);
//	printf("Nama : %s\nNIM : %s\nSemeester : %d\n%d %s %d\n",deovan.nama,deovan.nim,deovan.semester,deovan.dob.hari,namabulan[deovan.dob.bulan-1],deovan.dob.tahun);
//	
//	printf("Size dari mahasiswa = %d\n",sizeof(mahasiswa));
//	
//	mahasiswa LB07[40];
//	LB07[0]=deovan;
//	LB07[1]=charis;
	
	
	
//	MALLOC -> memory allocation
//	FREE -> melepaskan memory
//	int *p = (int *)malloc(sizeof(int));
//	*p = 10;
//	printf("p : %d %d %d\n",p,*p,&p);
//	getchar();
//	int *array = (int*)malloc(sizeof(int)*1000*1000*1000);
//	for(int i=0;i<1000*1000*1000;i++){
//		array[i] = i;
//	}
//	getchar();
//	free(array);
//	getchar();



//	MALLOC + POINTER
//	mahasiswa *berry = (mahasiswa*)malloc(sizeof(mahasiswa));
//	strcpy((*berry).nama, "Berry Prastaska");
//	strcpy(berry->nim,"2802410680");
//	berry->dob.hari = 23;
//	berry->dob.bulan = 7;
//	berry->dob.tahun = 2006;
//	berry->semester = 2;
//	printf("Nama : %s\n",berry->nama);
//	printf("NIM : %s\n",berry->nim);
//	printf("Semester : %d\n",berry->semester);
//	printf("%d %d %d\n",berry->dob.hari,berry->dob.bulan,berry->dob.tahun);

	
	
//  POINTER
//	int a = 10;
//	printf("Address a = %d %p\n",&a,&a);
//	
//	int *p = &a;
//	a = 7;
//	printf("Value a = %d %d\n",a,*p);
//	
//	int b = 5;
//	p = &b;//nilai p yang akan berubah. Jika hanya p akan dibaca membaca nilai
//	*p = 8;//nilai b yang akan berubah. Jika dengan *p akan dibaca mengubah nilai
//	printf("Value b = %d %d\n",b,*p);
//	printf("Value a = %d %d\n",a,*p);
//	
//	int arr[10] = {1,2,3,4,5,6,7,8,9};
//	printf("Arr = %d %d %d\n",&arr[0],&arr[1],&arr[2]);
//	printf("Arr = %d %d\n",arr, arr+1);//mengakses alamat nya
//	printf("Value = %d %d\n",*arr, *arr+1);//mengakses nilai nya
	
	return 0;
}
