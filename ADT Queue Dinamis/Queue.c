/*
Program : Queue.c
Author : 211524017 Muhammad Deo Audha Rizki
Kelas :
Deskripsi: Header file dari prototype Queue linked list
Tanggal : 13 Maret 2022
*/
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include "Queue.h"

//Prototype Queue/ primitif Queue dengan pointer
//Konstruktor
void CreateQueue(Queue *Q){
/* I.S : Q terdefinisi tidak diketahui isinya
F.S : Q diinisialisasi dengan HEAD(Q)=nil, TAIL(Q)=nil
*/
	HEAD(*Q) = nil;
	TAIL(*Q) = nil;
}

address Alokasi(int x){
/* mengirim sebuah address jika alokasi type Queue berhasil */
	//Kamus Lokal
	ElmQueue *P;
	
	//Algoritma
	P = (ElmQueue*) malloc (sizeof(ElmQueue));
	if(P != nil){
		info(P) = x;
		next(P) = nil;
		return P;
	}else{
		return nil;
	}
}

void DeAlokasi(address P){
/* P direlease dari memori */
	//Kamus
	
	//Algoritma
	free(P);
}

//Operasi Queue
void AddQue(Queue *Q, int X){
/* I.S : Q terdefinisi sembarang mungkin kosong
F.S : Q bertambah sebuah elemen bernilai X dibelakang
proses : HEAD (Q) merupakan elemen terakhir dari Q
*/
	address p;
	p = Alokasi(X);
	if(IsQueueEmpty(*Q)){
		HEAD(*Q) = p;
		TAIL(*Q) = p;
	}else{
		next(TAIL(*Q)) = p;
		TAIL(*Q) = next(TAIL(*Q));
	}
}

void DelQue(Queue *Q, int *y){
/* I.S : Q terdefinisi sembarang tidak kosong
F.S : Q berkurang satu elemen didepan disimpan pada y
proses : y=info(HEAD), HEAD(Q) = next(HEAD(Q))
DeAlokasi elemen pertama*/

	address pDel;
	pDel = HEAD(*Q);
	*y = info(pDel);
	
	if(next(pDel) == nil){
		HEAD(*Q) = nil;
		TAIL(*Q) = nil;
	}else{
		HEAD(*Q) = next(pDel);
		next(pDel) = nil;
	}
}


//Operasi I/O terhadap Queue
void CetakQueue(Queue Q){
/* I.S : Q terdefinisi sembarang tidak kosong
F.S : elemen Queue dicetak dilayar
*/
	ElmQueue *p;
	printf("isi queue dari mulai HEAD s.d. TAIL : \n");
	if(!IsQueueEmpty(Q)){
		p = HEAD(Q);
		printf("[ %d ]", info(p));
		p = next(p);
		while(p != nil){
			printf("[ %d ]", info(p));
			p = next(p);
		}
	}else{
		printf("[ Empty ]");
	}
}

//Operasi boolean dan relasi terhadap Queue
boolean IsQueueEmpty(Queue Q){
/* Mengirim true jika Queue kosong HEAD(Q)=nil
false sebaliknya */
	if(HEAD(Q) == nil){
		return true;
	}else{
		return false;
	}
}

boolean CariElemenQueue(Queue Q, int X){
/* mengirim true jika elemen x ada pada Q,
dan false jika x tidak ditemukan pada Q
skema pencarian dengan boolean
*/
	address p;
	boolean ketemu;
	
	p = HEAD(Q);
	ketemu = false;
	if(p == nil){
		return false;
	}else{
		while(next(p) != nil && !ketemu){
			if(X == info(next(p))){
				ketemu == true;
			}else{
				p = next(p);
			}
		}
	} 
	if(next(p) == nil){
		return false;
	}else{
		return true;
	}
}
