/* Program : barang.c
Deskripsi : Header ADT Barang
oleh : Muhammad Deo Audha Rizki
Tgl/Version :
*/
#include <stdio.h>
#include "barang.h"

BARANG CreateBarang(char *nama, long harga){
	BARANG B;
	B.nama_barang = nama;
	B.harga = harga;
	return B;
}

void SetNamaBarang(BARANG barang, char *nama){
	*(barang.nama_barang) = *nama;
}

char *GetNamaBarang(BARANG barang){
	return barang.nama_barang;
}

void SetHargaBarang(BARANG barang, long harga){
	barang.harga = harga;
}

int GetHargaBarang(BARANG barang){
	return barang.harga;
}

int GetHargaDiskon(BARANG barang, float diskon){
	return (barang.harga - ((barang.harga)*diskon/100));
}

void TampilBarang(BARANG barang){
	printf("%s\n%d", barang.nama_barang, barang.harga);
}

int isMember(char cek){
    scanf(" %c",&cek);
    if(cek=='Y'||'y'){
        return 1 ;
    }
    else{
        return 0;
    }
}



