/* File        : list1.c */
/* Deskripsi   : ADT list berkait dengan representasi fisik pointer */
/*		 Representasi address dengan pointer */
/*		 InfoType adalah integer */
/* Dibuat oleh : Muhammad Deo Audha Rizki */

#include "boolean.h"
#include <stdio.h>
#include "list.h"
#include <stdlib.h>

/*********** PROTOTYPE ****************/
/**** Predikat untuk test keadaan LIST  ****/
boolean ListEmpty (List L){
/* Mengirim true jika List Kosong */
	return (First(L)==Nil);
}

/**** Konstruktor/Kreator List Kosong ****/
void CreateList (List * L){
/* IS : L sembarang */
/* FS : Terbentuk List Kosong */
	First(*L) = Nil;
}

/**** Manajemen Memory ****/
address Alokasi (infotype X){
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address != Nil, 	   */
/*	dan misalnya menghasilkan P, maka Info(P) = X, Next(P) = Nil */
/* Jika alokasi gagal, mengirimkan Nil */

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
/* IS : P terdefinisi */
/* FS : P dikembalikan ke sistem */
/* Melakukan dealokasi / pengembalian address P ke system */
	free(P);
}

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

boolean FSearch (List L, address P){
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
	//Kamus Lokal
	address Q;
	boolean ketemu;
	
	//Algoritma
	Q = First(L);
	ketemu = false;
	while((Q != Nil) && !ketemu){
		if(Q == P){
			ketemu = true;
		}else{
			Q  = Next(Q);
		}
	}
	return ketemu;
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

/**** PRIMITIF BERDASARKAN NILAI ****/
/**** Penambahan Elemen ****/
void InsVFirst (List * L, infotype X){
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
	
	//Kamus Lokal
	address P;
	
	//Algoritma
	P = Alokasi(X);
	if(P !=  Nil){
		InsertFirst(L,P);
	}
}

void InsVLast (List * L, infotype X){
/* IS : L mungkin Kosong */
/* FS : melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir (elemen terakhir adalah yang baru) */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal IS = FS */

	//Kamus Lokal
	address P;
	
	//Algoritma
	P = Alokasi(X);
	if(P !=  Nil){
		InsertLast(L,P);
	}
}

/**** Penghapusan Elemen ****/
void DelVFirst (List * L, infotype * X){
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */
	//Kamus Lokal
	address P;
	
	//Algoritma
	DelFirst(L, &P);
	*X = Info(P);
	DeAlokasi(P);
}

void DelVLast (List * L, infotype * X){
/* IS : L TIDAK Kosong */
/* FS : Elemen pertama List dihapus, nilai info disimpan ke X */
/* 	dan alamat elemen pertama di dealokasi */

	//Kamus Lokal
	address P;
	
	//Algoritma
	DelLast(L,&P);
	(*X) = Info(P);
	DeAlokasi(P);
}

/**** PRIMITIF BERDASARKAN ALAMAT ****/
/**** Penambahan elemen berdasarkan alamat ****/
void InsertFirst (List * L, address P){
/* IS : L sembarang, P sudah dialokasi */
/* FS : menambahkan elemen ber-address P sebagai elemen pertama */
	
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter (List * L, address P, address Prec){
/* IS : Prec pastilah elemen List dan bukan elemen terakhir */
/*	P sudah dialokasi */
/* FS : Insert P sebagai elemen sesudah elemen beralamat Prec */
	Next(P) = Next(Prec);
	Next(Prec) = P;
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

/**** Penghapusan sebuah elemen ****/
void DelFirst (List * L, address * P){
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
		DelFirst(L,&P);
	}else{
		Prec = SearchPrec(*L,X);
		DelAfter(L,&P,Prec);
	}
}

void DelLast (List * L, address * P){
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

void DelAfter (List * L, address * Pdel, address Prec){
/* IS : L TIDAK Kosong, Prec adalah anggota List */
/* FS : menghapus Next(Prec): Pdel adalah alamat elemen list yang dihapus */
	
	*Pdel = Next(Prec);
	Next(Prec) = Next(*Pdel);
	Next(*Pdel) = Nil;
}

/**** PROSES SEMUA ELEMEN LIST  ****/
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

int NbElmt (List L){
/* Mengirimkan banyaknya elemen list, mengirimkan 0 jika list kosong */
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

address AdrMax (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
	return Search(L, Max(L));
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

address AdrMin (List L){
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
	return Search(L, Min(L));
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

/***************************************/
/*******  PROSES TERHADAP LIST  ********/
/***************************************/
void DelAll (List * L){
/* Delete semua elemen list dan alamat elemen di dealokasi */
	
	//Kamus data
	infotype X;
	
	//Algoritma
	while(!ListEmpty(*L)){	
	DelVFirst(L, &X);
	}
}

void InversList (List * L){
/* IS : L sembarang */
/* FS : Elemen List dibalik : elemen terakhir menjadi elemen pertama, dst */
/*	Membalik elemen list, tanpa melakukan alokasi / dealokasi */
	//Kamus data
	address P;
	List result;
	
	//Algoritma
	if(!ListEmpty(*L) && NbElmt(*L) > 1){
		CreateList(&result);
		while(!ListEmpty(*L)){
			DelLast(L,&P);
			InsertLast(&result, P);
		}
		First(*L) = First(result);
	}
}

List FInversList (List L){
/* Mengirimkan list baru, hasil invers dari L */
	//Kamus data
	List result;
	boolean error = false;
	infotype X;
	
	//Algoritma
	CreateList(&result);
	while(!error && !ListEmpty(L)){
		DelVFirst(&L,&X);
		
		if(Alokasi(X) == Nil){
			error = true;
		}else{
			InsVFirst(&result,X);
		}
	}
	if(error){
		DelAll(&result);
	}
	return result;
}

void CopyList (List L1, List * L2){
/* IS : L1 sembarang */
/* FS : L2 = l1 */
/* L1 dan L2 "menunjuk" ke list yang sama, Tidak ada alokasi / dealokasi */
	ListEmpty(*L2);
	First(*L2) = First(L1);
}

List FCopyList (List L){
/* Mengirimkan List yang merupakan salinan L */
	
	//Kamus Lokal
    List result;
    boolean error = false;
    address P;
    address X;

    /* ALGORITMA */
    CreateList(&result);
    P = First(L);

    while(!error && P != Nil) {
        X = Alokasi(Info(P));
        
        if (X == Nil) {
            error = true;
        } else {
            InsertLast(&result, X);
            P = Next(P);
        }
    }

    if (error) {
        DelAll(&result);
    }
    return result;
}

void CpAlokList (List Lin, List * Lout){
/* IS : Lin Sembarang */
/* FS : Jika semua alokasi berhasi, maka Lout berisi hasil copy Lin */
/* 	Jika ada alokasi yang gagal, maka Lout = Nil dan semua elemen yang */
/*	terlanjur di alokasi, maka didealokasikan */
/* 	Dengan melakukan alokasi elemen */
/*	Lout adalah  list kosong jika ada alokasi elemen yang gagal */
    /* KAMUS LOKAL */
    List copy;

    /* ALGORITMA */
    copy = FCopyList(Lin);
    First(*Lout) = First(copy);
}

void Konkat (List L1, List L2, List * L3){
/* IS : L1 dan L2 sembarang */
/* FS : L1 dan L2 tetap, L3 adalah hasil konkatenansi L1 dan L2 */
/*	Jika semua alokasi berhasil , maka L3 adalah hasil konkatenasi */
/*	Jika ada alokasi gagal, semua elemen yang sudah di alokasi harus */
/* 	di dealokasi dan L3 = Nil */
/* Konkatenasi dua buah list : L1 dan L2 menghasilkan L3 yang "baru" */
/* Elemen L3 adalah hasil alokasi elemen yang "baru". Jika ada alokasi yang */
/*	  GAGAL, maka L3 harus bernilai nil dan semua elemen yang pernah di */
/*	  alokasi didealokasi */
    /* KAMUS LOKAL */
    boolean error;
    infotype X;

    /* ALGORITMA */
    error = false;

    if (ListEmpty(L1) && ListEmpty(L2)) {
        CreateList(L3);
    } else if (ListEmpty(L1) && !ListEmpty(L2)) {
        CpAlokList(L2, L3);
    } else if (!ListEmpty(L1) && ListEmpty(L2)) {
        CpAlokList(L1, L3);
    } else {
        CpAlokList(L1, L3);
        if (!ListEmpty(*L3)) {
            while (!ListEmpty(L2) && !error) {
                DelVFirst(&L2, &X);
                
                if (Alokasi(X) == Nil) {
                    error = true;
                } else {
                    InsVLast(L3, X);
                }
            }
            if (error) {
                DelAll(L3);
            }
        }
    }
}

void Konkat1 (List * L1, List * L2, List * L3){
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
            DelVFirst(&L, &X);
            InsVFirst(L2, X);
        } else {
            start = NbElmt(L)/2;
            end = NbElmt(L) - start;

            for (i = 0; i < start; i++) {
                DelVFirst(&L, &X);
                InsVLast(L1, X);
            }

            for (j = 0; j < end; j++) {
                DelVFirst(&L, &X);
                InsVLast(L2, X);
            }
        }
    }
}
