/*
Program : mahasiswa.h
Author : 211524017, Muhammad Deo Audha Rizki
Kelas : 1A
Deskripsi: Header file dari prototype linear linked list mahasiswa
Tanggal : 9 Maret 2022
*/

#ifndef _LIST_H
#define _LIST_H
#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define Nil NULL
#define InfoT(P) (P)->tinggiBadan
#define InfoN(P) (P)->nama
#define Next(P) (P)->next
#define First(M) (M).First
typedef struct tElmtList *address; // pointer menunjuk ke alamat tElmtList
typedef char *infonama;
typedef int infotinggi;


typedef struct tElmtList{
infonama nama;
infotinggi tinggiBadan;
address next;
} Mahasiswa;
typedef struct{
address First;
} List;

//===================Creator===================
Mahasiswa CreateMahasiswa(char *nama, int tinggi);
//Fungsi untuk menghasilkan data mahasiswa berdasarkan
//nilai-nilai dari program atau modul pemanggil

void CreateList (List *L);
/* I.S : L terdefinisi, tidak diketahui nilainya
F.S : L diinisialisasi first(L) = nil
*/

//===================Destructor===================

address Alokasi (Mahasiswa X);
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
//===================Validator===================
boolean isValid(Mahasiswa M);
//Fungsi untuk menegecek apakah data valid atau tidak
//Fungsi ini mengembalikan nilai true jika nama tidak kosong dan tinggi > 0

boolean ListEmpty(List L);
// mengecek apakah jumlah elemen pada List kosong
// mengirimkan true jika List kosong, mengirimkan false jika tidak
//=========================================================================
/**** Pencarian sebuah elemen List ****/
address Search (List L, Mahasiswa X);
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */

//===================Get Set===================
void setNama(Mahasiswa *M, char *nama);
//Mengubah nama dari sebuah data Mahasiswa

char *getNama(Mahasiswa M);
//Mengembalikan nama dari sebuah data Mahasiswa

void setTinggi(Mahasiswa *M, int Tinggi);
//Mengubah Tinggi dari sebuah data Mahasiswa

char getTinggi(Mahasiswa M);
//Mengembalikan Tinggi dari sebuah data Mahasiswa



//===================Print Object===================
void PrintObj(Mahasiswa M);
//Menampilkan Mahasiswa
void PrintInfo (List L);
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */


//=========================================================================
/** { KELOMPOK Interaksi operasi linear list, baca tulis } **/
/**Penambahan Elemen***/
void InsFirst (List *L, Mahasiswa M);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen pertama pada List dengan nilai M jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/

void InsertFirst (List * L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */

void InsLast (List * L, Mahasiswa M);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen terakhir pada List dengan nilai M jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/

void InsertLast (List * L, address P);
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

void InsAfter (List * L, Mahasiswa X, Mahasiswa Y);
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dengan nilai X dan
menambahkan elemen list setelah Y ditemukan pertama kali pada list
*/
boolean DataSame(Mahasiswa X, Mahasiswa Y);
/* Fungsi ini mengembalikan nilai true jika data X = data Y */

void InsertAfter (List * L, address P, address Prec);
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsSorted(List *L, Mahasiswa X);
/*I.S : L Terdefinisi
F.S : Melakukan alokasi sebuah elemen dengan nilai X dan menambahkan
elemen list sesuai urutan ascending nama
*/

/*Penghapusan Elemen*/
void DelFirst (List * L, Mahasiswa *M);
/*I.S : L tidak kosong
F.S : Elemen pertama List dihapus, nilai info disimpan ke M
dan alamat elemen pertama di dealokasi. Sehingga elemen pertama pada List
adalah elemen berikutnya sebelum penghapusan.
*/
void DelF (List * L, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */

void DelP (List * L, Mahasiswa M);
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = M */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

void DelLast (List *L, Mahasiswa *M);
/*I.S : L tidak kosong
F.S : Elemen terakhir list dihapus: nilai info disimpan pada M
dan alamat elemen terakhir di dealokasi. Sehingga elemen terakhir pada
List adalah elemen sebelumnya sebelum penghapusan.*/

void DelL (List * L, address * P);
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */

void DelAfter (List * L, infonama *N, infonama M, infotinggi *X);
/*I.S : L terdefinisi, mungkin kosong
  F.S : melakukan dealokasi sebuah elemen dengan nama N setelah nama M
  pertama ditemukan pada list.
  Nilai N dan X yang dihapus dalam list akan disimpan sebagai keluaran dari
  prosedur
*/
void DelA (List * L, address * Pdel, address Prec);
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */

void DelAll (List * L);
/* Delete semua elemen list dan alamat elemen di dealokasi */

void DelSame(address head);
/*Menghapus elemen yang sama pada list*/

/** KELOMPOK OPERASI LAIN TERHADAP TYPE **/
int NbElmt (List L);
// Mengirimkan banyaknya elemen List atau mengirimkan 0 jika List kosong

address Search (List L, Mahasiswa X);
/* Mencari apakah ada elemen list dengan Info (P)= X
Jika ada, mengirimkan address elemen tersebut yang pertama kali ditemukan.
jika tidak ada, mengirimkan Nil
*/
address SearchN (List L, infonama N);
/* Mencari apakah ada elemen list dengan InfoN(P)= N
   Jika ada, mengirimkan address elemen tersebut yang pertama kali ditemukan.
   jika tidak ada, mengirimkan Nil
*/
void InversList (List *L);
/* I.S : L sembarang
F.S : Mengubah Elemen list menjadi terbalik, yaitu elemen terakhir
menjadi elemen pertama, elemen kedua menjadi elemen sebelum terakhir dst
Membalik elemen list, tanpa melakukan alokasi / dealokasi
*/


List FCopyListCriteria (List L, int Tinggi);
/* Fungsi ini mengembalikan List salinan dari L berdasarkan kriteria yang ditentukan*/

#endif
