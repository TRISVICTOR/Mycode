/*
#include<stdio.h>

//Global Variable
//Kelebihan utama -> Nilainya tidak garbage
//Kelemahan utama -> Nilainya itu sangat mudah diubah / terbawa
//2D Char Array kalau global variable -> semuanya \0
char house[105][105]; //Untuk map / rumah bibi
int startRow, startCol; //Untuk kasih tau lokasi baris dan kolom titik S
int count; //Untuk menyimpan hasil akhir berapa lantai yang perlu diganti Bibi

void floodfill(char house[105][105], int row, int col){
	//Stop Trigger
	if(house[row][col] == '#' || house[row][col] == '\0' || house[row][col] == '\n'){
		return;
	}
	
	if(house[row][col] == '.'){
		count++;
		house[row][col] = '#';
	}
	
	floodfill(house, row+1, col); //ke bawah
	floodfill(house, row-1, col); //ke atas
	floodfill(house, row, col+1); //kanan
	floodfill(house, row, col-1); //kiri
}


int main(){
	int tc;
	scanf("%d",&tc);
	
	for(int k = 1 ; k <= tc ; k++){
		int row, column;
		scanf("%d %d",&row, &column);
		
		//Scan rumah Bibi
		for(int i = 0 ; i < row ; i++){
			for(int j = 0 ; j < column + 1; j++){ // + 1 untuk menangkap \n
				scanf("%c", &house[i][j]);
				if(house[i][j] == 'S'){
					startRow = i;
					startCol = j;
				}
			}
		}
		
		floodfill(house, startRow, startCol); //Start dari Titik S
		printf("Case #%d: %d\n",k, count);
		//Case 1 => Count = 8
		//Case 2 => Nilai awal count bukan 0, melainkan 8
		//Perlu kita melakukan reset value
		//Kembalikan semua ke default value (integer jadi 0, char jadi \0)
		count = 0 , startRow = 0, startCol = 0;
		for(int i = 0 ; i < 105 ; i++){
			for(int j = 0 ; j < 105 ; j++){
				house[i][j] = '\0';
			}
		}
	}
	return 0;
}
*/

#include<stdio.h>

int flood(int x, int y, int r, int c, char map[100][100]){
	if(map[x][y] == '#'){ //kalo wall
		return 0;
	}
	
	int f = 0;
	if(map[x][y] == '.'){ //kalo floor 
		f = 1;
	}
	
	map[x][y] = '#'; //(ganti floor jadi wall) biar ga diitung 2x 
	
	if(x > 0) f += flood(x - 1, y, r, c, map);       // top
    if(x < r - 1) f += flood(x + 1, y, r, c, map);   // bottom
    if(y > 0) f += flood(x, y - 1, r, c, map);       // left
    if(y < c - 1) f += flood(x, y + 1, r, c, map);   // right
	
	return f;
	
	
}

int main(){
	
	int tc;
	scanf("%d", &tc); getchar();
	
	
	for(int i = 0; i < tc; i++){
		int r, c;
		scanf("%d %d", &r, &c); getchar();
		
		char map[100][100];
		int x, y;
		
		for(int j = 0; j < r; j++){
			 
			for(int k = 0; k < c; k++){
				scanf("%c", &map[j][k]);
				if(map[j][k] == 'S'){
					x = j;
					y = k;
				}
			}
			getchar();
		}
		
		int tile = flood(x, y, r, c, map);
		printf("Case #%d: %d\n", i + 1, tile);
		
	}
	
	
	return 0;
}
