#include <stdio.h>
#include <string.h>

struct Student {
    char first_name[16];
    char last_name[16];
    int count;  // Menyimpan jumlah kemunculan nama lengkap, mulai dari 1
};

int find_student(struct Student students[], int count, char *first_name, char *last_name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].first_name, first_name) == 0 && strcmp(students[i].last_name, last_name) == 0) {
            return i;  // Mengembalikan indeks jika ditemukan
        }
    }
    return -1;  // Mengembalikan -1 jika tidak ditemukan
}

int main() {
    int N;
    scanf("%d", &N);  // Membaca jumlah siswa

    struct Student students[100];  // Array untuk menyimpan data siswa
    int student_count = 0;  // Counter untuk jumlah siswa yang telah diproses

    for (int i = 0; i < N; i++) {
        char first_name[16], last_name[16];
        scanf("%s %s", first_name, last_name);  // Membaca nama depan dan nama belakang

        int index = find_student(students, student_count, first_name, last_name);

        if (index == -1) {
            // Jika siswa belum ada dalam daftar, tambahkan ke array
            strcpy(students[student_count].first_name, first_name);
            strcpy(students[student_count].last_name, last_name);
            students[student_count].count = 1;  // Inisialisasi dengan 1 (dimulai dari 1)
            printf("%s%s%04d\n", first_name, last_name, students[student_count].count);  // Menampilkan ID dengan format 4 digit
            student_count++;
        } else {
            // Jika siswa sudah ada, increment jumlah kemunculan
            students[index].count++;
            printf("%s%s%04d\n", first_name, last_name, students[index].count);  // Menampilkan ID yang telah diupdate
        }
    }

    return 0;
}
