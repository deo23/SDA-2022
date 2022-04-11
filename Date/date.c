/*
Program : date.c
Deskripsi : Body ADT POINT
Created : Muhammad Deo Audha Rizki
Modified : 
Tanggal : 27 Februari 2022
*/

#include <stdio.h>
#include "boolean.h"
#include "date.h"

/*********** Operasi Primitif ************/
void CreateDate (date * D){
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
(*D).Tgl = 1;
(*D).Bln = 1;
(*D).Thn = 1990;
}

/******* Selector komponen **********/
int GetTgl (date D){
/* Mengambil bagian Tgl dari date */
return D.Tgl;
}

int GetBln (date D){
/* Mengambil bagian Bln dari date */
return D.Bln;
}

int GetThn (date D){
/* Mengambil bagian Thn dari date */
return D.Thn;
}

/****** Pengubah komponen ******/
void SetTgl (int NewTgl, date * D){
/* Memberi nilai untuk Tgl */
(*D).Tgl = NewTgl;
}

void SetBln (int NewBln, date * D){
/* Memberi nilai untuk Bln */
(*D).Bln = NewBln;
}

void SetThn (int NewThn, date * D){
/* Memberi nilai untuk Thn */
(*D).Thn = NewThn;
}

/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/

void BacaDate (date * D){
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
int iTgl, iBln, iThn;
scanf("%d %d %d", &iTgl, &iBln, &iThn);
(*D).Tgl = iTgl;
(*D).Bln = iBln;
(*D).Thn = iThn;
}

boolean isValid(date D){
/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
/*KAMUS LOKAL*/
boolean cek;
/*ALGORITMA*/
  cek = false;
  if (D.Thn > 0)
   {
    switch (D.Bln){
	
     case 1:
        if (D.Tgl>0 && D.Tgl < 32) 
         cek = true;
       	break;
     case 2:
        if (isKabisat(D)) 
         {
           if (D.Tgl>0 && D.Tgl < 30) 
            cek = true;
         }
        else
         {
           if (D.Tgl>0 && D.Tgl < 29)
            cek = true;
         }
       	break;
     case 3:
        if (D.Tgl>0 && D.Tgl < 32) 
         cek = true;
         break;
       
     case 4:
        if(D.Tgl>0 && D.Tgl < 31) 
         cek = true;
       break;
     case 5:
        if (D.Tgl>0 && D.Tgl < 32) 
         cek = true;
       	break;
     case 6:
        if(D.Tgl>0 && D.Tgl < 31) 
         cek = true; 
       	break;
     case 7:
        if (D.Tgl>0 && D.Tgl < 32) 
         cek = true;
       break;
     case 8:
        if(D.Tgl>0 && D.Tgl < 32) 
         cek = true;
       break;
     case 9:
        if (D.Tgl>0 && D.Tgl < 31) 
         cek = true;
       break;
     case 10:
        if(D.Tgl>0 && D.Tgl < 32) 
         cek = true;
       break; 
     case 11: 
        if(D.Tgl>0 && D.Tgl < 31) 
         cek = true;
         break;
    
     case 12:
        if (D.Tgl>0 && D.Tgl < 32) 
         cek = true;         
        break;     
    }   
}
return cek;
}


void PrintObj (date D){
/* Print nilai D dengan format dd/mm/yyyy */
printf("%d/%d/%d", D.Tgl, D.Bln, D.Thn);
}

/****** Operator Relasional ******/
boolean isKabisat (date D){
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja */
boolean cek;

	if (D.Thn % 4 == 0) {
		if(D.Thn % 100 == 0){
			if(D.Thn % 400 == 0){
				cek = true;
			}
			else{
				cek = false;
			}
			
		}else{
			cek = true;
		}
			
	}else{
		cek = false;
	}
	return cek;
}

int TglAkhir (date D){
/* Memberikan tanggal terakhir dari sebuah bulan */
/*KAMUS LOKAL*/
int tgl;
/*ALGORITMA*/
  if (isValid(D))
   {
    switch (D.Bln){
	
     case 1:
        
         tgl = 31;
       	break;
     case 2:
        if (isKabisat(D)) 
         {
           
            tgl = 29;
         }
        else
         {
           
            tgl = 28;
         }
       	break;
     case 3:
        
         tgl = 31;
         break;
       
     case 4:
         
         tgl = 30;
       break;
     case 5:
         
         tgl = 31;
       	break;
     case 6:
        
         tgl = 30;
       	break;
     case 7:
         
         tgl = 31;
       break;
     case 8:
         
         tgl = 31;
       break;
     case 9:
        
         tgl = 30;
       break;
     case 10:
        
         tgl = 31;
       break; 
     case 11: 
         
         tgl = 30;
         break;
    
     case 12:
        
         tgl = 31;        
        break;     
    }   
}
return tgl;
}

void DateBefore (date D){

/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */

//if there is first day of month
	if(D.Tgl==1)
	{
		//months which have 30 days in previous month
		if(D.Bln==4|| D.Bln==6|| D.Bln==9|| D.Bln==11)
		{
			D.Tgl=31;
			D.Bln = D.Bln -1;	
		}
		//for MARCH, to define february last day
		else if(D.Bln==3)
		{
			if(isKabisat(D))	
				D.Tgl=29;
			else
				D.Tgl=28;
			
			D.Bln = D.Bln -1;
		}
		//for January, to define December last day
		else if(D.Bln==1)
		{
			D.Tgl=31;
			D.Bln = 12;
			D.Thn = D.Thn - 1 ;
		}
		//for Feb, to define January last day
		else if(D.Bln==2)
		{
			D.Tgl=31;
			D.Bln = D.Bln -1;
		}
		//for other months
		else
		{
			D.Tgl=30;
			D.Bln = D.Bln -1;
		}
	}
	//other days of month
	else
	{
		D.Tgl = D.Tgl-1;
	}
	PrintObj(D);	

}

void NextDate (date D){
/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
	
	//Cek apakah tanggal 28, 30, atau 31
	if(isValid(D)){
		if(D.Tgl > 0 && D.Tgl < 28){ //checking for day from 0 to 27
			D.Tgl += 1;
		}
		else if(D.Tgl == 28){
			if(D.Bln == 2){ //checking for february
				if(isKabisat(D)){ //checking leap year
					D.Tgl = 29;
				}
				else{
					D.Tgl = 1;
					D.Bln = 3;
				}
			}
			else{ //when its not feb
				D.Tgl+=1;
			}
		}
		else if(D.Tgl == 29){ //last day check for feb
			if(D.Bln == 2){
				D.Tgl = 1;
				D.Bln = 3;
			}
			else{
				D.Tgl += 1;
			}
		}
		else if(D.Tgl == 30){ //last day check for april,june,September,November
			if(D.Bln == 1 || D.Bln == 3 || D.Bln == 5 || D.Bln == 7 || D.Bln == 8 || D.Bln == 10 || D.Bln == 12 ){
				D.Tgl += 1;
			}
			else{
				D.Tgl = 1;
				D.Bln += 1;
			}
		}
		else if(D.Tgl == 31){ //last day of the month
			D.Tgl = 1;
			if(D.Bln == 12){ //checking for last day of the year
				D.Thn += 1;
				D.Bln = 1;
			}
			else{
				D.Bln += 1;
			}
		}
		PrintObj(D);	
	}
}

void SelisihDate (date D1, date D2){
/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
	int n1, n2, i;
	int Bulan[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	// initialize count using years and day
	n1 = D1.Thn * 365 + D1.Tgl;
	
	// Add days for months in given date
	for(i = 0; i < D1.Bln - 1; i++){
		n1 += Bulan[i];
	}
	
	// SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'D2'
	n2 = D2.Thn * 365 + D2.Tgl;
	
	for(i = 0; i < D2.Bln - 1; i++){
		n2 += Bulan[i];
	}
	
	printf("%d\n", n2-n1);
}
