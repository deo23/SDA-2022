/*
Program : Queue.h
Author : 211524017 Muhammad Deo Audha Rizki
Kelas : 1A
Deskripsi: Body file dari Kasus 1 Queue (Cuci Mobil 3)
Tanggal : 15 Maret 2022
*/
#ifndef _QUEUE_H
#define _QUEUE_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
//pendefinisian pointer
#define nil NULL
#define info(P) (P)->info
#define infonama(P) (P)->info.nama
#define infoarr(P) (P)->info.arrival
#define infotime(P) (P)->info.time_size
#define infoser(P) (P)->info.service
#define infofin(P) (P)->info.finish
#define next(P) (P)->next
#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL
//Pembentukan tipe Queue dan struct MOBIL
typedef struct{
	char nama[12];
	int arrival;
	int time_size;
	int service;
	int finish;
} MOBIL;
typedef struct tElmQueue *address;
typedef struct tElmQueue{
MOBIL info;
address next;
}ElmQueue;
typedef struct{

address HEAD;
address TAIL;
}Queue;

//Prototype Queue/ primitif Queue dengan pointer
//Konstruktor
void CreateQueue(Queue *Q);
/* I.S : Q terdefinisi tidak diketahui isinya
F.S : Q diinisialisasi dengan HEAD(Q)=nil, TAIL(Q)=nil
*/
address Alokasi(MOBIL x);
/* mengirim sebuah address jika alokasi type Queue berhasil */
void DeAlokasi(address P);
/* P direlease dari memori */

//Operasi Queue
void AddQue(Queue *Q, MOBIL X);
/* I.S : Q terdefinisi sembarang mungkin kosong
F.S : Q bertambah sebuah elemen bernilai X dibelakang
proses : HEAD (Q) merupakan elemen terakhir dari Q
*/
void DelQue(Queue *Q, MOBIL*y);
/* I.S : Q terdefinisi sembarang tidak kosong
F.S : Q berkurang satu elemen didepan disimpan pada y
proses : y=info(HEAD), HEAD(Q) = next(HEAD(Q))
DeAlokasi elemen pertama

*/
//Operasi I/O terhadap Queue
void CetakQueue(Queue Q);
/* I.S : Q terdefinisi sembarang tidak kosong
F.S : elemen Queue dicetak dilayar
*/
//Operasi boolean dan relasi terhadap Queue
boolean IsQueueEmpty(Queue Q);
/* Mengirim true jika Queue kosong HEAD(Q)=nil
false sebaliknya */

//Operasi untuk struct MOBIL
void updateWaktu(MOBIL *M, Queue Q, int finish);
/* Prosedur untuk mengupdate waktu antrian yang masuk */

MOBIL JenisMobil(int jenis);
/* Fungsi untuk menentukan jenis mobil berdasarkan nomor tipe
dengan return MOBIL */

#endif

