/* File stack.c */ 
/* HEAD dan TAIL adalah alamat elemen pertama dan terakhir */ 
/* Kapasitas Queue=MaxEl bush elemen, dan indeks dibuat "sirkuler" */ 
#include "stack.h"
#include <stdio.h>
#include <string.h>
/* Definisi ABSTRACT DATA TYPE POINT *
Stack S;

/******************* Prototype ****************/
/*** Konstruktor/Kreator ***/
void CreateEmpty(Stack *S){
	Top(*S) = Nil;
}
/* T.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosonq berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+l karena O tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsEmpty (Stack S){
	return Top(S) == Nil;
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S){
	return Top(S) == MaxEl;
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
/*********** Menambahkan sebuah elemen ke Stack **********/
void Push (Stack *S, infotype X){
	Top(*S) = Top(*S)+1;
	strcpy(InfoTop(*S), X); 
}
/* Menambahkan X sebagai elemen Stack S. */
/* T.S. S mungkin kosong, tabel penampung elemen stack TTDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
/*********** Menqhapus sebuah elemen Stack **********/
void Pop (Stack *S, infotype *X){
	strcpy(*X, InfoTop(*S));
	Top(*S) = Top(*S)-1;
}
/* Menghapus X dari Stack S. */
/* T.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang l */

void PrintStack(Stack S){
	int i;
	for(i=Top(S); i >= 1; i--){
		printf("%s\n", S.T[i]);
	}
}
/*Menampilkan nilai-nilai pada Stack S yang diurutkan berdasarkan data yang pertama kali masuk ke stack*/

boolean checkPop(Stack S, infotype X){
	if(strcmp(InfoTop(S), X) == 0){
		return true;
	}else{
		return false;
	}
}

void MoveEl(Stack *P, Stack *S, infotype *X){
	infotype temp;
	
	do{
		Pop(S, &temp);
		Push(P, temp);
		printf("Mengeluarkan mobil %s dari area parkir\n", temp);
	}while(strcmp(InfoTop(*S), *X) != 0);
	Pop(S, &temp);
	printf("\nMobil %s keluar dari area parkir\n", temp);	
	printf("\n==========Di luar area parkir==========\n");
	PrintStack(*P);		
	printf("\n==========Di dalam area parkir==========\n");
	if(!IsEmpty(*S)){
		PrintStack(*S);
	}else{
		printf("KOSONG");
	}
	
	do{
		Push(S, InfoTop(*P));
		Pop(P, &temp);
		printf("Memasukkan mobil %s ke area parkir\n", temp);
	}while(!IsEmpty(*P));
	printf("\n==========Di dalam area parkir==========\n");
	PrintStack(*S);
}

boolean find(Stack S, infotype X){
	int i;
	boolean ketemu = false;
	for(i = 1; i<=Top(S); i++){
		if(strcmp((S).T[i], X) == 0){
			ketemu = true;
		}
	}
	return ketemu;
}

void cekArah(int arah){
	if(arah == 1){
		printf("\nMobil akan keluar ke arah kiri\n");
		printf("Mengeluarkan mobil yang menghalangi ke arah kanan\n");
	}else{
		printf("\nMobil akan keluar ke arah kanan\n");
		printf("Mengeluarkan mobil yang menghalangi ke arah kiri\n");
	}
}
