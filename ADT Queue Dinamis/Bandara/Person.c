/*
Program : Queue.c
Author : 211524017 Muhammad Deo Audha Rizki
Kelas : 1A
Deskripsi: Header file dari Kasus 1 Queue (Cuci Mobil 3)
Tanggal : 15 Maret 2022
*/
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include "Person.h"

//Prototype Queue/ primitif Queue dengan pointer
//Konstruktor
void CreateQueue(Queue *Q){
/* I.S : Q terdefinisi tidak diketahui isinya
F.S : Q diinisialisasi dengan HEAD(Q)=nil, TAIL(Q)=nil
*/
	HEAD(*Q) = nil;
	TAIL(*Q) = nil;
}

address Alokasi(PERSON x){
/* mengirim sebuah address jika alokasi type Queue berhasil */
	//Kamus Lokal
	ElmQueue *P;
	
	//Algoritma
	P = (ElmQueue*) malloc (sizeof(ElmQueue));
	if(P != nil){
		strcpy(infonama(P), x.nama);
		infoarr(P) = x.arrival;
		infokoper(P) = x.koper;
		infotime(P) = x.time_size;
		infoser(P) = x.service;
		infofin(P) = x.finish;
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
void AddQue(Queue *Q, PERSON X){
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

void DelQue(Queue *Q, PERSON *y){
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
	printf("Isi queue dari mulai antrian pertama sampai antrian terakhir : \n");
	if(!IsQueueEmpty(Q)){
		p = HEAD(Q);
		printf("[ Nama: %s, Waktu datang : %d, Jumlah Koper : %d , Lama antrian : %d , Finish : %d  ]\n", infonama(p), infoarr(p), infokoper(p), infotime(p), infofin(p));
		p = next(p);
		while(p != nil){
			printf("[ Nama: %s, Waktu datang : %d, Jumlah Koper : %d , Lama antrian : %d , Finish : %d  ]\n", infonama(p), infoarr(p), infokoper(p), infotime(p), infofin(p));
			p = next(p);
		}
	}else{
		printf("[ Empty ]");
	}
}

void CetakInfo(PERSON P){
	printf("Waktu Mengantri: %d\n", P.time_size);
	printf("Estimasi selesai: %d\n", P.finish);
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


void updateWaktu(PERSON *P, Queue Q, int finish){
	if(!IsQueueEmpty(Q)){
	
		(*P).service = 0;
		(*P).finish = 0;	
		if(finish < (*P).arrival){
			(*P).time_size = 0;
		}else{			
			(*P).time_size = finish - (*P).arrival;
		}		
		(*P).service = 5 + 3*(*P).koper;
		(*P).finish = finish + (*P).service;
	}else{
		(*P).service = 0;
		(*P).finish = 0;	
		(*P).time_size = 0;
		(*P).service = 5 + 3*(*P).koper;
		(*P).finish = finish + (*P).service + (*P).arrival;
	}
}








