/*
Program : main.c
Author : 211524017, Muhammad Deo Audha Rizki
Kelas : 1A
Deskripsi: main driver dari prototype linear linked list mahasiswa
Tanggal : 9 Maret 2022
*/

#include <stdio.h>
#include <stdlib.h>
#include "mahasiswa.h"


int main(int argc, char *argv[]) {
	printf("====Driver List Linier Mahasiswa====\n");
	printf("====Studi Kasus Kedua====\n");
	List L1, L2;	
	printf("2) Pembuatan List kosong\n");
	CreateList(&L1);
	CreateList(&L2);
	printf("Test list kosong\n");
	printf("List 1 = ");PrintInfo(L1);printf("\n");
	printf("List 2 = ");PrintInfo(L2);printf("\n");
	printf("3) Mengisi List 1 dengan beberapa elemen terurut ascending\n");
	//Mahasiswa 1
	Mahasiswa M1;
	char *nama1 = "Basudara";
	int tinggi1 = 180;	
	M1 = CreateMahasiswa(nama1,tinggi1);
	address P = Alokasi(M1);
	InsertFirst(&L1, P);
	//Mahasiswa 2
	Mahasiswa M2;
	char *nama2 = "Ilham";
	int tinggi2 = 180;
	M2 = CreateMahasiswa(nama2,tinggi2);
	InsSorted(&L1,M2);
	//Mahasiswa 3
	Mahasiswa M3;
	char *nama3 = "Windah";
	int tinggi3 = 170;
	M3 = CreateMahasiswa(nama3,tinggi3);
	InsSorted(&L1, M3);
	//Mahasiswa 4
	Mahasiswa M4;
	char *nama4 = "Ilham";
	int tinggi4 = 150;
	M4 = CreateMahasiswa(nama4,tinggi4);
	InsSorted(&L1, M4);
	printf("4) Menampilkan List L1\n");
	printf("List 1 = ");PrintInfo(L1);printf("\n");
	printf("5) Menampilkan jumlah elemen pada List L1\n");
	printf("Jumlah elemen L1 : %d\n", NbElmt(L1));
	printf("6) Menyalin List L1 yang dengan data tinggi > 170 ke List L2\n");
	L2 = FCopyListCriteria(L1,170);
	printf("7) Menampilkan List L2\n");
	printf("List 2 = ");PrintInfo(L2);printf("\n");
	printf("8) Menghapus data duplikat pada List L1\n");
	DelSame(First(L1));
	printf("9) Menampilkan list L1 yang baru\n");
	printf("List 1 = ");PrintInfo(L1);printf("\n");
	printf("10) Menghapus List 1 dan List 2\n");
	DelAll(&L1);
	DelAll(&L2);
	printf("List 1 = ");PrintInfo(L1);printf("\n");
	printf("List 2 = ");PrintInfo(L2);printf("\n");
	return 0;
}
