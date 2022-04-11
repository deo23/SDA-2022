/*
Program : Queue.h
Author : 211524017 Muhammad Deo Audha Rizki
Kelas :
Deskripsi: Header file dari prototype Queue linked list
Tanggal : 13 Maret 2022
*/
#ifndef _QUEUE_H
#define _QUEUE_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
//pendefinisian pointer
#define nil NULL
#define info(P) (P)->info
#define next(P) (P)->next
#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL
//Pembentukan tipe Queue
typedef struct tElmQueue *address;
typedef struct tElmQueue{
int info;
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
address Alokasi(int x);
/* mengirim sebuah address jika alokasi type Queue berhasil */
void DeAlokasi(address P);
/* P direlease dari memori */

//Operasi Queue
void AddQue(Queue *Q, int X);
/* I.S : Q terdefinisi sembarang mungkin kosong
F.S : Q bertambah sebuah elemen bernilai X dibelakang
proses : HEAD (Q) merupakan elemen terakhir dari Q
*/
void DelQue(Queue *Q, int *y);
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
boolean CariElemenQueue(Queue Q, int X);
/* mengirim true jika elemen x ada pada Q,
dan false jika x tidak ditemukan pada Q
skema pencarian dengan boolean
*/
#endif
