/*
Program : list.h
Author : 211524017, Muhammad Deo Audha Rizki
Kelas : 1A
Deskripsi: Header file dari prototype linear linked list
Tanggal : 8 Maret 2022
*/
#ifndef _LIST_H
#define _LIST_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#define Nil NULL
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) (L).First
/** Definisi ABSTRACT DATA TYPE List **/
/*Definisi List :*/
/* List kosong ===> First (L) =Nil
Setiap elemen dengan address P dapat diacu info (P) dan Next (P);
Elemen terakhir list ===> Jika addressnya Last maka Next (Last) = Nil
*/
typedef struct tElmtList *address; // pointer menunjuk ke alamat tElmtList
typedef int infotype;
typedef struct tElmtList{
infotype info;
address next;
} ElmtList;
typedef struct{
address First;
} List;
//======================================================================
/* Prototype Linear List */
/* Konstruktor membentuk List */
void CreateList (List *L);
/* I.S : L terdefinisi, tidak diketahui nilainya
F.S : L diinisialisasi first(L) = nil
*/
/* Destruktor/Dealokator: */
address Alokasi (infotype X);
/*Mengirimkan address hasil alokasi sebuah elemen
Jika alokasi berhasil, maka address !=Nil,
dan misalnya menghasilkan P, maka Info(P)= x, Next(P)=Nil
Jika alokasi gagal, mengirimkan Nil
*/
void DeAlokasi (address P);
/*I.S : P terdefinisi
F.S : P dikembalikan ke sistem
Melakukan dealokasi/ pengembalian address P ke system
*/
//========================================================================
/** { KELOMPOK OPERASI Cek Elemen kosong atau penuh} **/

boolean ListEmpty(List L);
// mengecek apakah jumlah elemen pada List kosong
// mengirimkan true jika List kosong, mengirimkan false jika tidak
//=========================================================================
/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X);
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */

address SearchPrec (List L, infotype X);
//=========================================================================
/** { KELOMPOK Interaksi operasi linear list, baca tulis } **/
/**Penambahan Elemen***/
void InsFirst (List *L, infotype X);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen pertama pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/

void InsertFirst (List * L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */

void InsLast (List * L, infotype X);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen terakhir pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/

void InsertLast (List * L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

void InsAfter (List * L, infotype X, infotype Y);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dengan nilai x dan
menambahkan elemen list setelah y ditemukan pertama kali pada list
*/

void InsertAfter (List * L, address P, address Prec);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */

/*Penghapusan Elemen*/
void DelFirst (List * L, infotype *X);
/*I.S : L tidak kosong
F.S : Elemen pertama List dihapus, nilai info disimpan ke X
dan alamat elemen pertama di dealokasi. Sehingga elemen pertama pada List
adalah elemen berikutnya sebelum penghapusan.
*/
void DelF (List * L, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

void DelP (List * L, infotype X);
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelLast (List *L, infotype *X);
/*I.S : L tidak kosong
F.S : Elemen terakhir list dihapus: nilai info disimpan pada X
dan alamat elemen terakhir di dealokasi. Sehingga elemen terakhir pada
List adalah elemen sebelumnya sebelum penghapusan.*/

void DelL (List * L, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */

void DelAfter (List * L, infotype *X, infotype Y);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan dealokasi sebuah elemen dengan nilai x setelah nilai y
pertama ditemukan pada list.
Nilai x yang dihapus dalam list akan disimpan sebagai keluaran dari
prosedur
*/
void DelA (List * L, address * Pdel, address Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */

void DelAll (List * L);
/* Delete semua elemen list dan alamat elemen di dealokasi */

/*Menampilkan Elemen*/
void PrintInfo (List L);
/* I.S : L terdefinisi, mungkin kosong
F.S : Jika List tidak kosong, menampilkan semua info yang disimpan pada
elemen list ke layar. jika List kosong, hanya menampilkan pesan ?list
kosong?
*/

//=========================================================================

/** KELOMPOK OPERASI LAIN TERHADAP TYPE **/
int NbElmt (List L);
// Mengirimkan banyaknya elemen List atau mengirimkan 0 jika List kosong
address Search (List L, infotype X);
/* Mencari apakah ada elemen list dengan Info (P)= X
Jika ada, mengirimkan address elemen tersebut yang pertama kali ditemukan.
jika tidak ada, mengirimkan Nil
*/
void InversList (List *L);
/* I.S : L sembarang
F.S : Mengubah Elemen list menjadi terbalik, yaitu elemen terakhir
menjadi elemen pertama, elemen kedua menjadi elemen sebelum terakhir dst
Membalik elemen list, tanpa melakukan alokasi / dealokasi
*/
List getNewInversList (List L);
// Mengirimkan list baru, hasil invers dari L

infotype Min (List L);
/* Mengirimkan nilai Info(P) yang minimum */

infotype Max (List L);
/* Mengirimkan nilai Info(P) yang maksimum */

void PecahList (List * L1, List * L2, List L);
/* IS : L mungkin kosong */
/* FS : berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah : untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil , maka separuh adalah NbElmt (L) div 2 */

infotype Average (List L);
/* Mengirimkan nilai rata-rata Info(P) */

void Konkat (List * L1, List * L2, List * L3);
/* IS : L1 dan L2 sembarang */
/* FS : L1 dan L2 kosong, L3 adalah hasil konkatenansi L1 dan L2 */
/*	Konkatenasi dua buah List L1 dan L2; menghasilkan L3 yang baru */
/* 	(dengan elemen List L1 dan L2) */
/*	dan L1 serta L2 menjadi list kosong */
/* 	Tidak ada alokasi / dealokasi pada procedure ini */
#endif

