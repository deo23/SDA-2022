#include <iostream>
#include "boolean.h"
#include <stdio.h>
#include "list.h"
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	printf("====Driver List Linier====\n");
	List L;

	printf("Pembuatan List kosong\n");
	CreateList(&L);
	printf("Test list kosong\n");
	printf("F.S L adalah list Kosong\n");
	if (ListEmpty(L))
		printf("L Empty");
	else
		printf("L not Empty");

	printf("\n====manajemen memory====\n");
	// Alokasi adress P dengan nilai 1 dan menjadikan P sebagai elemen pertama List L
	int x = 2;
	address P = Alokasi(x);
	printf("\n====Primitif berdasarkan alamat====\n");
	printf("Menambahkan elemen ber address P sebagai elemen pertama L (2)\n");
	InsertFirst(&L, P);
	printf("L = ");  PrintInfo(L); printf("\n");
	

	printf("\n====Primitif berdasarkan nilai====\n");
	printf("Menambahkan 1 sebagai elemen pertama dan 3 sebagai elemen terkahir List\n");
	InsVFirst(&L, 1);
	InsVLast(&L, 3);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menghapus elemen pertama dan elemen terkahir sebuah List\n");
	int x1, x2;
	DelVFirst(&L, &x1);
	DelVLast(&L, &x2);
	printf("Elemen pertama : %d\nElemen terakhir : %d\n", x1, x2);
	printf("L = ");  PrintInfo(L); printf("\n");
	
	printf("\n====Primitif berdasarkan alamat====\n");
	printf("Menambahkan 0 sebagai elemen pertama, 1 setelah elemen pertama dan 3 sebagai elemen terkahir List\n");
	int y1 = 0;
	int y2 = 1;
	int y3 = 3;
	address Q1 = Alokasi (y1);
	address Q2 = Alokasi(y2);
	address Q3 = Alokasi(y3);
	InsertFirst(&L, Q1);
	InsertAfter(&L,Q2,Q1);
	InsertLast(&L,Q3);
	printf("L = ");  PrintInfo(L); printf("\n");
	
	printf("Membuat sebuah List baru L1=[15,16,17]\n");
	List L1; 
	CreateList(&L1);
	InsVFirst(&L1, 15);
	InsVLast(&L1, 16);
	InsVLast(&L1, 17);
	printf("L1 = ");  
	PrintInfo(L1); 
	printf("\n");

	printf("\n====Proses terhadap List====\n");
	printf("Konkat antara list L dengan L1\n");
	printf("L = "); 
	PrintInfo(L); 
	printf("\n");
	printf("L1 = "); 
	PrintInfo(L1); 
	printf("\n");
	List L2;
	Konkat1(&L, &L1, &L2);
	printf("hasil konkat = "); 
	PrintInfo(L2); 
	printf("\n");
	printf("\n====Proses terhadap elemen dalam list====\n");
	printf("List L2\n");
	printf("Banyak elemen L2 = %d\nNilai Max = %d\nNilai Min = %d\n", NbElmt(L2), Max(L2), Min(L2));
	printf("Rata - rata elemen L2 = %d\n", Average(L2));
	printf("Membalik elemen pada list L2\n");
	InversList(&L2);
	printf("L2 = ");  PrintInfo(L2); printf("\n");
	printf("Memecah elemen pada list L2\n");
	PecahList(&L,&L1,L2);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("L1 = ");  PrintInfo(L1); printf("\n");

	return 0;
}
