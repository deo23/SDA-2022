/*
Program : mahasiswa.c
Author : 211524017, Muhammad Deo Audha Rizki
Kelas : 1A
Deskripsi: Body file dari prototype linear linked list mahasiswa
Tanggal : 9 Maret 2022
*/

#include "boolean.h"
#include <stdio.h>
#include <conio.h>
#include "mahasiswa.h"
#include <stdlib.h>

//===================Creator===================
Mahasiswa CreateMahasiswa(char *nama, int tinggi){
//Fungsi untuk menghasilkan data mahasiswa berdasarkan
//nilai-nilai dari program atau modul pemanggil
	Mahasiswa M;
	M.nama = nama;
	M.tinggiBadan = tinggi;
	
	return M;
}
void CreateList (List *L){
/* I.S : L terdefinisi, tidak diketahui nilainya
F.S : L diinisialisasi first(L) = nil
*/
	First(*L) = Nil;
}
//===================Destructor===================

address Alokasi (Mahasiswa X){
/*Mengirimkan address hasil alokasi sebuah elemen
Jika alokasi berhasil, maka address !=Nil,
dan misalnya menghasilkan P, maka Info(P)= x, Next(P)=Nil
Jika alokasi gagal, mengirimkan Nil
*/
	//Kamus Lokal
	address P;
	
	//Algoritma
	P = (address) malloc (sizeof(Mahasiswa));
	if(P != Nil){
		InfoT(P) = X.tinggiBadan;
		InfoN(P) = X.nama;
		Next(P) = Nil;
		return P;
	}else{
		return Nil;
	}
}

void DeAlokasi (address P){
/*I.S : P terdefinisi
F.S : P dikembalikan ke sistem
Melakukan dealokasi/ pengembalian address P ke system
*/
	free(P);
}
//===================Validator===================
boolean isValid(Mahasiswa M){
//Fungsi untuk menegecek apakah data valid atau tidak
//Fungsi ini mengembalikan nilai true jika nama tidak kosong dan tinggi > 0
	if (M.nama != Nil && M.tinggiBadan > 0){
		return true;
	}else{
	return false;
	}	
}

boolean ListEmpty(List L){
// mengecek apakah jumlah elemen pada List kosong
// mengirimkan true jika List kosong, mengirimkan false jika tidak	
	return (First(L)==Nil);
}
//=========================================================================
/**** Pencarian sebuah elemen List ****/
address Search (List L, Mahasiswa X){
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address elemen tsb. */
/* Jika tidak ada, mengirimkan Nil */
	
	//Kamus Lokal
	address P;
	boolean ketemu;
	
	//Algoritma
	P = First(L);
	ketemu = false;
	while((P != Nil) && !ketemu){
		if(X.nama == InfoN(P) && X.tinggiBadan == InfoT(P)){
			ketemu = true;
		}else{
			P  = Next(P);
		}
	}
	return P;
}

address SearchN (List L, infonama N)
/* Mencari apakah ada elemen list dengan InfoN(P)= N
   Jika ada, mengirimkan address elemen tersebut yang pertama kali ditemukan.
   jika tidak ada, mengirimkan Nil
*/
{
    while(First(L) != Nil) {
        if(InfoN(First(L)) == N) {
            return First(L);
        }
        First(L) = Next(First(L));
    }
    return Nil;
}
address SearchPrec (List L, Mahasiswa X){
/* Mengirimkan address elemen sebelum elemen yang nilainya = X */
/* Mencari apakah ada elemen list dengan Info(P) = X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec) = P dan Info(P) = X */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec = Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

	//Kamus Lokal
	address P;
	boolean ketemu;
	
	//Algoritma
	P = First(L);
	ketemu = false;
	if(P == Nil){
		return Nil;
	}else{
		while((Next(P) != Nil) && !ketemu){
			if(X.nama == InfoN(Next(P)) && X.tinggiBadan == InfoT(Next(P))){
				ketemu = true;
			}else{
				P = Next(P);
			}
		}
	}
	if(Next(P) == Nil){
		return Nil;
	}else{
		return P;
	}
}

//===================Get Set===================
void setNama(Mahasiswa *M, char *nama){
//Mengubah nama dari sebuah data Mahasiswa
	(*M).nama = nama;
}

char *getNama(Mahasiswa M){
//Mengembalikan nama dari sebuah data Mahasiswa
	return M.nama;
}

void setTinggi(Mahasiswa *M, int Tinggi){
//Mengubah Tinggi dari sebuah data Mahasiswa
	(*M).tinggiBadan = Tinggi;
}

char getTinggi(Mahasiswa M){
//MengembalikanTinggi dari sebuah data Mahasiswa
	return M.tinggiBadan;
}
//===================Print Object===================
void PrintObj(Mahasiswa M){
//Menampilkan Mahasiswa
	printf("%s, %d", M.nama, M.tinggiBadan);
}

void PrintInfo (List L){
/* IS : L mungkin kosong */
/* FS : Jika List tidak kosong, semua info yang disimpan pada elemen list */
/*	diprint. Jika list kosong, hanya menuliskan "List Kosong" */

	//Kamus Lokal
	address P;
	
	//Algoritma
	if(ListEmpty(L)){
		printf("[]");
	}else{
		printf("[");
		P = First(L);
		while(P != Nil){
			if(Next(P) == Nil){
				printf("(%s,%d)]", InfoN(P), InfoT(P));
			}else{
				printf("(%s,%d),", InfoN(P), InfoT(P));
			}
			P =Next(P);
		}
	}
}


//=========================================================================
/** { KELOMPOK Interaksi operasi linear list, baca tulis } **/
/**Penambahan Elemen***/
void InsFirst (List *L, Mahasiswa X){
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen pertama pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS*/
	//Kamus Lokal
	address P;
	
	//Algoritma
	P = Alokasi(X);
	if(P !=  Nil){
		InsertFirst(L,P);
	}
}
void InsertFirst (List * L, address P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
	
	Next(P) = First(*L);
	First(*L) = P;
}

void InsLast (List * L, Mahasiswa X){
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dan
menambahkan elemen terakhir pada List dengan nilai X jika alokasi
berhasil. Jika alokasi gagal IS = FS
*/
	//Kamus Lokal
	address P;
	
	//Algoritma
	P = Alokasi(X);
	if(P !=  Nil){
		InsertLast(L,P);
	}
}

void InsertLast (List * L, address P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : P ditambahkan sebagai elemen terakhir yang baru */

	//Kamus data
	address Last;
	
	//Algoritma
	Last = First(*L);
	if(First(*L) == Nil){
		InsertFirst(L,P);
	}else{
		while(Next(Last) != Nil){
			Last = Next(Last);
		}
		InsertAfter(L,P,Last);
	}
}


void InsAfter(List *L, Mahasiswa X, Mahasiswa Y)
{
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dengan nilai X dan
menambahkan elemen list setelah Y ditemukan pertama kali pada list
*/
    address Q = Alokasi(X);
    address P = Search(*L, Y);
    Mahasiswa M;
    M.nama = InfoN(P);
    M.tinggiBadan = InfoT(P);
    if (Q != Nil && DataSame(M, Y))
    {
        Next(Q) = Next(P);
        Next(P) = Q;
    }
}
boolean DataSame(Mahasiswa X, Mahasiswa Y)
{
    return (X.tinggiBadan == Y.tinggiBadan && (strcmp(X.nama, Y.nama) == 0));
}

void InsertAfter (List * L, address P, address Prec){
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsSorted(List *L, Mahasiswa X)
{
    address P = First(*L);
    address Prec = Nil;
    Mahasiswa Y;
    while (P != Nil && strcmp(InfoN(P), X.nama) < 0)
    {
        Prec = P;
        P = Next(P);
        Y.nama = InfoN(Prec);
        Y.tinggiBadan = InfoT(Prec);
    }
    if (Prec == Nil)
    {
        InsFirst(L, X);
    }
    else
    {
        InsAfter(L, X, Y);
    }
}

/*Penghapusan Elemen*/
void DelFirst (List * L, Mahasiswa *X){
/*I.S : L tidak kosong
F.S : Elemen pertama List dihapus, nilai info disimpan ke X
dan alamat elemen pertama di dealokasi. Sehingga elemen pertama pada List
adalah elemen berikutnya sebelum penghapusan.*/
	//Kamus Lokal
	address P;
	
	//Algoritma
	DelF(L, &P);
	(*X).nama = InfoN(P);
	(*X).tinggiBadan = InfoT(P);
	DeAlokasi(P);
}
void DelF (List * L, address * P){
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen pertama list sebelum penghapusan */
/*	elemen list berkurang satu (mungkin menjadi kosong) */
/* First elemen yang baru adalah suksessor elemen pertama yang lama */
	*P = First(*L);
	if(Next(*P) != Nil){
		First(*L) = Next(*P);
		Next(*P) = Nil;
	}else{
		CreateList(L);
	}
}

void DelP (List * L, Mahasiswa X){
/* IS : L sembarang */
/* FS : Jika ada elemen list beraddress P, dengan Info(P) = X */
/* 	Maka P dihapus dari list dan di dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
	
	//Kamus Lokal
	address P, Prec;
	
	//Algoritma
	P = Search(*L,X);
	if(P == First(*L)){
		DelF(L,&P);
	}else{
		Prec = SearchPrec(*L,X);
		DelA(L,&P,Prec);
	}
}
void DelLast (List *L, Mahasiswa *X){
/*I.S : L tidak kosong
F.S : Elemen terakhir list dihapus: nilai info disimpan pada X
dan alamat elemen terakhir di dealokasi. Sehingga elemen terakhir pada
List adalah elemen sebelumnya sebelum penghapusan.*/
	//Kamus Lokal
	address P;
	
	//Algoritma
	DelL(L,&P);
	(*X).nama = InfoN(P);
	(*X).tinggiBadan = InfoT(P);
	DeAlokasi(P);
}
void DelL (List * L, address * P){
/* IS : L TIDAK kosong */
/* FS : P adalah alamat elemen terakhir list sebelum penghapusan */
/*	Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last elemen baru adalah predesessor elemen terakhir yang lama, jika ada */
	//Kamus Lokal
	address Last, PrecLast;
	
	//Algoritma
	Last = First(*L);
	PrecLast = Nil;
	while(Next(Last) != Nil){
		PrecLast = Last;
		Last = Next(Last);
	}
	*P = Last;
	if(PrecLast == Nil){
		First(*L) = Nil;
	}else{
		Next(PrecLast) = Nil;
	}
}

void DelAfter (List * L, infonama *N, infonama M, infotinggi *X)
/*I.S : L terdefinisi, mungkin kosong
  F.S : melakukan dealokasi sebuah elemen dengan nama N setelah nama M
  pertama ditemukan pada list.
  Nilai N dan X yang dihapus dalam list akan disimpan sebagai keluaran dari
  prosedur
*/
{
    if(!ListEmpty(*L)) {
        address P = SearchN(*L, M), pDel = Next(P);
        *N = InfoN(pDel);
        *X = InfoT(pDel);
        Next(P) = Next(pDel);
        DeAlokasi(pDel); 
    }
}

void DelA (List * L, address * Pdel, address Prec){
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
	
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	Next(*Pdel) = Nil;
}

void DelAll (List * L){
/* Delete semua elemen list dan alamat elemen di dealokasi */
	
	//Kamus data
	Mahasiswa X;
	
	//Algoritma
	while(!ListEmpty(*L)){	
	DelFirst(L, &X);
	}
}

void DelSame(address head)
/* I.S: List L terdefinisi dan masih ada elemen duplikat
 * F.S: Seluruh elemen list L telah unique (tidak ada duplikat)
 */
{
    address P = head;
	address next;
	
	if (P == Nil) {
		return;
	}
	
	while (Next(P) != Nil) {
		if (strcmp(InfoN(P), InfoN(Next(P))) == 0) {
			next = Next(Next(P));
			free(Next(P));
			Next(P) = next;
		} else {
			P = Next(P);
		}
	}
}

/** KELOMPOK OPERASI LAIN TERHADAP TYPE **/
int NbElmt (List L){
// Mengirimkan banyaknya elemen List atau mengirimkan 0 jika List kosong
	//Kamus Lokal
	address P;
	int N = 0;
	
	//Algoritma
	if(ListEmpty(L)){
		return 0;
	}
	
	P = First(L);
	
	while(P != Nil){
		N += 1;
		P = Next(P);
	}
	return N;
}



void InversList (List *L){
/* I.S : L sembarang
F.S : Mengubah Elemen list menjadi terbalik, yaitu elemen terakhir
menjadi elemen pertama, elemen kedua menjadi elemen sebelum terakhir dst
Membalik elemen list, tanpa melakukan alokasi / dealokasi
*/
	//Kamus data
	address *P;
	List result;
	
	//Algoritma
	if(!ListEmpty(*L) && NbElmt(*L) > 1){
		CreateList(&result);
		while(!ListEmpty(*L)){
			DelL(L,&P);
			InsertLast(&result, P);
		}
		First(*L) = First(result);
	}
}

List FCopyListCriteria (List L, int Tinggi){
/* Mengirimkan List yang merupakan salinan L */
	
	//Kamus Lokal
    List result;
    boolean error = false;
    address P;
    address X;
    Mahasiswa M;

    /* ALGORITMA */
    CreateList(&result);
    P = First(L);
	
    while(!error && P != Nil) {
    	M.nama = InfoN(P);
		M.tinggiBadan = InfoT(P);
        X = Alokasi(M);
        
        if (X == Nil) {
            error = true;
        } else if (InfoT(P) > Tinggi) {
            InsertLast(&result, X);
            P = Next(P);
        }else{
        	P = Next(P);
		}
    }

    if (error) {
        DelAll(&result);
    }
    return result;
}
