#include "boolean.h"
#include <stdio.h>
#include "list.h"
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
int main() {
	printf("====Driver List Linier====\n");
	printf("====Studi Kasus Pertama====\n");
	List L;
	printf("Pembuatan List kosong\n");
	CreateList(&L);
	printf("Test list kosong\n");
	printf("F.S L adalah list Kosong\n");
	if (ListEmpty(L))
		printf("L Empty");
	else
		printf("L not Empty");

	// Alokasi adress P dengan nilai 1 dan menjadikan P sebagai elemen pertama List L
	int x = 7;
	address P = Alokasi(x);
	printf("\nMenambahkan elemen ber address P sebagai elemen pertama L (7)\n");
	InsertFirst(&L, P);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menambahkan elemen 11 setelah elemen 7\n");	
	InsLast(&L,11);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menambahkan elemen 9 diantara 7 dan 11\n");	
	int y=9;
	address Q = Alokasi(y);
	InsertAfter(&L, Q ,P);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menambahkan elemen 5 di awal list\n");	
	InsFirst(&L, 5);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menambahkan elemen 13 di akhir list\n");	
	InsLast(&L,13);
	printf("L = ");  PrintInfo(L); printf("\n");		
	printf("Menghapus elemen terkahir(13) sebuah List\n");
	int x1;	
	DelLast(&L, &x1);	
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menghapus bilangan 7 pada sebuah List\n");
	DelP(&L,7);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menghapus elemen pertama (5) sebuah list\n");
	int x2;
	DelFirst(&L,&x2);
	printf("L = ");  PrintInfo(L); printf("\n");
	printf("Menghapus list deret bilangan ganjil\n");
	DelAll(&L);
	printf("L = ");  PrintInfo(L); printf("\n");
	


	return 0;
}
*/

int main(){
	//{Kamus Data}
	List L;
	ElmtList *P, *Q;
	int info;
	//{Algoritma}
	CreateList(&L);
	InsLast(&L, 'M');
	InsLast(&L, 'A');
	InsLast(&L, 'L');
	InsLast(&L, 'A');
	InsLast(&L, 'M');
	Q = NULL;
	P = First(L);
	if (P != Nil) {
	 if(Next(P) != Nil){
	 while (Next(P) != NULL) {
	 Q = P;
	 P = Next(P);
	 }
	 Next(Q) = NULL;
	 }else{
	 //L = NULL;
	 }
	 printf("Nilai Info adalah %c", Info(P));
	 printf("Nilai Info adalah %c", Info(Q));
	}
}



