/* File        : list.c */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Muhammad Deo Audha Rizki */

#include "boolean.h"
#include <stdio.h>
#include "list.h"
#include <stdlib.h>

//======================================================================
/* Prototype Linear List */
/* Konstruktor membentuk List */
void CreateList (List *L){
/* I.S : L terdefinisi, tidak diketahui nilainya
F.S : L diinisialisasi first(L) = nil
*/
	First(*L) = Nil;
}

/* Destruktor/Dealokator: */
address Alokasi (infotype X){
/*Mengirimkan address hasil alokasi sebuah elemen
Jika alokasi berhasil, maka address !=Nil,
dan misalnya menghasilkan P, maka Info(P)= x, Next(P)=Nil
Jika alokasi gagal, mengirimkan Nil
*/
	//Kamus Lokal
	address P;
	
	//Algoritma
	P = (address) malloc (sizeof(ElmtList));
	if(P != Nil){
		Info(P) = X;
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

//========================================================================
/** { KELOMPOK OPERASI Cek Elemen kosong atau penuh} **/

boolean ListEmpty(List L){
// mengecek apakah jumlah elemen pada List kosong
// mengirimkan true jika List kosong, mengirimkan false jika tidak	
	return (First(L)==Nil);
}
//==================================================
/**** Pencarian sebuah elemen List ****/
address Search (List L, infotype X){
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
		if(X == Info(P)){
			ketemu = true;
		}else{
			P  = Next(P);
		}
	}
	return P;
}
address SearchPrec (List L, infotype X){
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
			if(X == Info(Next(P))){
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

//=========================================================================
/** { KELOMPOK Interaksi operasi linear list, baca tulis } **/
/**Penambahan Elemen***/
void InsFirst (List *L, infotype X){
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

void InsLast (List * L, infotype X){
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

void InsAfter (List * L, infotype X, infotype Y){
/*I.S : L terdefinisi, mungkin kosong
F.S : melakukan alokasi sebuah elemen dengan nilai x dan
menambahkan elemen list setelah y ditemukan pertama kali pada list
*/

}

void InsertAfter (List * L, address P, address Prec){
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

/*Penghapusan Elemen*/
void DelFirst (List * L, infotype *X){
/*I.S : L tidak kosong
F.S : Elemen pertama List dihapus, nilai info disimpan ke X
dan alamat elemen pertama di dealokasi. Sehingga elemen pertama pada List
adalah elemen berikutnya sebelum penghapusan.*/
	//Kamus Lokal
	address P;
	
	//Algoritma
	DelF(L, &P);
	*X = Info(P);
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

void DelP (List * L, infotype X){
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

void DelLast (List *L, infotype *X){
/*I.S : L tidak kosong
F.S : Elemen terakhir list dihapus: nilai info disimpan pada X
dan alamat elemen terakhir di dealokasi. Sehingga elemen terakhir pada
List adalah elemen sebelumnya sebelum penghapusan.*/
	//Kamus Lokal
	address P;
	
	//Algoritma
	DelL(L,&P);
	(*X) = Info(P);
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
	infotype X;
	
	//Algoritma
	while(!ListEmpty(*L)){	
	DelFirst(L, &X);
	}
}

/*Menampilkan Elemen*/
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
				printf("%d]", Info(P));
			}else{
				printf("%d,", Info(P));
			}
			P =Next(P);
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
	address P;
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

List getNewInversList (List L){
// Mengirimkan list baru, hasil invers dari L
	//Kamus data
	List result;
	boolean error = false;
	infotype X;
	
	//Algoritma
	CreateList(&result);
	while(!error && !ListEmpty(L)){
		DelFirst(&L,&X);
		
		if(Alokasi(X) == Nil){
			error = true;
		}else{
			InsFirst(&result,X);
		}
	}
	if(error){
		DelAll(&result);
	}
	return result;
}

infotype Min (List L){
/* Mengirimkan nilai Info(P) yang minimum */

	//Kamus data
	infotype min;
	address P;
	
	//Algoritma
	min = Info(First(L));
	P = Next(First(L));
	
	while(P != Nil){
		if(Info(P) < min){
			min = Info(P);
		}
		P = Next(P);
	}
	return min;
}

infotype Max (List L){
/* Mengirimkan nilai Info(P) yang maksimum */
	
	//Kamus data
	infotype max;
	address P;
	
	//Algoritma
	max = Info(First(L));
	P = Next(First(L));
	
	while(P != Nil){
		if(Info(P) > max){
			max = Info(P);
		}
		P = Next(P);
	}
	return max;
}

void PecahList (List * L1, List * L2, List L){
/* IS : L mungkin kosong */
/* FS : berdasarkan L, dibentuk dua buah list L1 dan L2 */
/* L tidak berubah : untuk membentuk L1 dan L2 harus alokasi */
/* L1 berisi separuh elemen L dan L2 berisi sisa elemen L */
/* Jika elemen L ganjil , maka separuh adalah NbElmt (L) div 2 */
    /* KAMUS LOKAL */
    infotype X;
    int start, end;
    int i, j;

    /* ALGORITMA */
    CreateList(L1);
    CreateList(L2);

    if (!ListEmpty(L)) {
        if (NbElmt(L) == 1) {
            DelFirst(&L, &X);
            InsFirst(L2, X);
        } else {
            start = NbElmt(L)/2;
            end = NbElmt(L) - start;

            for (i = 0; i < start; i++) {
                DelFirst(&L, &X);
                InsLast(L1, X);
            }

            for (j = 0; j < end; j++) {
                DelFirst(&L, &X);
                InsLast(L2, X);
            }
        }
    }
}

infotype Average (List L){
/* Mengirimkan nilai rata-rata Info(P) */

	//Kamus data
	address P;
	float sum = 0;
	
	//Algoritma
	
		P = First(L);
		sum = Info(P);
		P = Next(P);
		while(P != Nil){
			sum += Info(P);
			P = Next(P);
		}
		return (sum/NbElmt(L));
	
}

void Konkat (List * L1, List * L2, List * L3){
/* IS : L1 dan L2 sembarang */
/* FS : L1 dan L2 kosong, L3 adalah hasil konkatenansi L1 dan L2 */
/*	Konkatenasi dua buah List L1 dan L2; menghasilkan L3 yang baru */
/* 	(dengan elemen List L1 dan L2) */
/*	dan L1 serta L2 menjadi list kosong */
/* 	Tidak ada alokasi / dealokasi pada procedure ini */
    /* KAMUS LOKAL */
    address P;

    /* ALGORITMA */
    if (ListEmpty(*L1)) {
        First(*L3) = First(*L2);
    } else if (ListEmpty(*L2)) {
        First(*L3) = First(*L1);
    } else {
        First(*L3) = First(*L1);
        P = First(*L1);
        while (Next(P) != Nil) {
            P = Next(P);
        }
        Next(P) = First(*L2);
    }
    CreateList(L1);
    CreateList(L2);
}

