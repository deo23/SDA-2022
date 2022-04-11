/*
Program : Queue.c
Author : 211524017 Muhammad Deo Audha Rizki
Kelas :
Deskripsi: Body file dari Kasus 2 Queue (Cuci Mobil 4)
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

address Alokasi(MOBIL x){
/* mengirim sebuah address jika alokasi type Queue berhasil */
	//Kamus Lokal
	ElmQueue *P;
	
	//Algoritma
	P = (ElmQueue*) malloc (sizeof(ElmQueue));
	if(P != nil){
		strcpy(infonama(P), x.nama);
		infoarr(P) = x.arrival;
		infotime(P) = x.time_size;
		infoser(P) = x.service;
		infofin(P) = x.finish;
		infojeda(P) = x.jeda;
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
void AddQue(Queue *Q, MOBIL X){
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

void DelQue(Queue *Q, MOBIL *y){
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
	printf("isi queue dari mulai antrian pertama sampai antrian terakhir : \n");
	if(!IsQueueEmpty(Q)){
		p = HEAD(Q);
		printf("[ Jenis: %s, Time Size : %d, Arrival : %d , Service : %d , Finish : %d  ]\n", infonama(p), infotime(p), infoarr(p), infoser(p), infofin(p));
		p = next(p);
		while(p != nil){
			printf("[ Jenis: %s, Time Size : %d, Arrival : %d , Service : %d , Finish : %d  ]\n", infonama(p), infotime(p), infoarr(p), infoser(p), infofin(p));
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

//Operasi untuk struct MOBIL
void updateWaktu(MOBIL *M, Queue Q, int finish){
	if(!IsQueueEmpty(Q)){
		(*M).service = 0;
		(*M).finish = 0;	
		(*M).service = finish + (*M).jeda;
		(*M).finish = (*M).time_size + (*M).service;
	}else{
		(*M).service = 0;
		(*M).finish = 0;	
		(*M).service = finish;
		(*M).finish = (*M).time_size + (*M).service;
	}
			
}

MOBIL JenisMobil(int jenis){
	MOBIL m;
	switch(jenis){
		case 1:
			strcpy(m.nama,"Mobil Kecil");
			m.time_size = 20;
			m.jeda = 1;
			
			break;
		case 2:
			strcpy(m.nama, "SUV");
			m.time_size = 30;
			m.jeda = 2;
			
			break;
		case 3:
			strcpy(m.nama, "SUV-2");
			m.time_size = 45;
			m.jeda = 4;
			
			break;
		case 4:
			strcpy(m.nama, "Mini");
			m.time_size = 60;
			m.jeda = 5;
			break;
			
		case 5:
			strcpy(m.nama, "Truck-1");
			m.time_size = 80;
			m.jeda = 6;			
			break;
		case 6:
			strcpy(m.nama, "Truck-2");
			m.time_size = 100;
			m.jeda = 8;
			
			break;
		case 7:
			strcpy(m.nama, "Truck-3");
			m.time_size = 120;
			m.jeda = 9;
			
			break;
		case 8:
			strcpy(m.nama, "Bus");
			m.time_size = 120;
			m.jeda = 9;
		
			break;
	}
	return m;
}

