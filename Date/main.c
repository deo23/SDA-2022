#include <stdio.h>
#include "date.h"

int main(){
	date D, DD;
	
	//CreateDate
	//Menginisialisasi Date dengan 1/1/1990
	printf("=====CreateDate : =====");
	printf("\nMenginisialisasi Date dengan 1/1/1990\n");
	CreateDate(&DD);	
	PrintObj(DD);
	printf("\n");
	
	//BacaDate
	//Membentuk Date dari input user
	printf("\n=====BacaDate : =====");
	printf("\nMembentuk Date dari input user\n");
	BacaDate(&D);
	PrintObj(D);
	
	//GetDate
	//Menampilkan masing-masing tgl, bln, thn
	printf("\n\n=====Get : =====");
	printf("\nSebelum Set\n");
	printf("Tanggal : ");
	printf("%d\n", GetTgl(D));
	printf("Bulan : ");
	printf("%d\n", GetBln(D));
	printf("Tahun : ");
	printf("%d\n", GetThn(D));
	
	//SetDate
	//Mengubah nilai tgl, bln, thn
	printf("\n=====Set : =====\n");
	SetTgl(31, &D);
	SetBln(12, &D);
	SetThn(2021, &D);
	printf("Setelah Set\n");
	printf("Tanggal : ");
	printf("%d\n", GetTgl(D));
	printf("Bulan : ");
	printf("%d\n", GetBln(D));
	printf("Tahun : ");
	printf("%d\n", GetThn(D));
	
	//Mengecek kevalidan tanggal
	printf("\n=====isValid : =====\n");
	if(isValid(D)){
		printf("Valid\n");
	}
	else{
		printf("Tidak Valid\n");
	}

	
	//Mengecek Kabisat
	printf("\n=====isKabisat : =====\n");
	if(isKabisat(D)){
		printf("Tahun Kabisat\n");
	}
	else{
		printf("Bukan Tahun Kabisat\n");
	}
	
	//Tanggal akhir
	printf("\n=====TglAkhir : =====\n");
	printf("Tanggal akhir : %d\n", TglAkhir(D));
	
	//Mengecek Tanggal sebelum
	printf("\n=====DateBefore : =====\n");
	printf("Tanggal sebelum :");
	DateBefore(D);
	printf("\n");
	
	
	
	//Mengecek Tanggal sesudah
	printf("\n=====NextDate : =====\n");
	printf("Tanggal sesudah :");
	NextDate(D);
	printf("\n");
	
	//Mengecek Selisih tanggal
	printf("\n=====SelisihDate : =====\n");
	printf("Selisih antara ");
	PrintObj(D);
	printf(" dan ");
	PrintObj(DD);
	printf(" : ");
	SelisihDate(DD, D);
}
	
