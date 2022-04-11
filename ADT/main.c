#include <stdio.h>
#include <stdlib.h>
#include "point.h"
#include "line.h"

int main(int argc, char *argv[]) {
POINT p, q, r, s, t, u, v, w, start1, end1, start2, end2;
LINE L1, L2, L3;
int x=0, y=0, xx=0, yy=0, panjang, panjang2;
/*
printf("===========UJI COBA POINT===========\n");
scanf("%d %d", &x, &y); // input atribut point dari user
p = CreatePoint(x,y); // buat point dari inputan user
printf("POINT p berada pada koordinat : ");
PrintPoint(p);//menampilkan point p
printf("\nKoordinat x pada POINT p berada pada titik : ");
printf("%d", GetX(p));//menampilkan koordinat x dari point p
printf("\nKoordinat y pada POINT p berada pada titik : ");
printf("%d", GetY(p));//menampilkan koordinat y point p
printf("\n");
scanf("%d %d", &xx, &yy); // input atribut point dari user
MakePoint(&q, xx, yy);
printf("POINT q berada pada koordinat : ");
PrintPoint(q);//menampilkan point q
printf("\nKoordinat x pada POINT q berada pada titik : ");
printf("%d", GetX(q));//menampilkan koordinat x dari point q
printf("\nKoordinat y pada POINT q berada pada titik : ");
printf("%d", GetY(q));//menampilkan koordinat y point q
printf("\n");
printf("Jarak antara p dan q : ");
printf("%d",Jarak(p,q));
ReSet(&p);
printf("\nPOINT p setelah di reset : ");
PrintPoint(p);//menampilkan point p
*/
printf("\n===========UJI COBA LINE===========\n");
//Membuat Line ke-1 dengan CreateLine
printf("Membuat Line ke-1 dengan CreateLine\n");
scanf("%d %d\n", &x, &y); // input atribut point dari user
r = CreatePoint(x,y); // buat point dari inputan user
scanf("%d %d", &xx, &yy); // input atribut point dari user
s = CreatePoint(xx,yy); // buat point dari inputan user
L1 = CreateLine(r,s);
//Menampilkan Line ke-1 dengan PrintLine
printf("Menampilkan Line ke-1 dengan PrintLine\n");
PrintLine(L1);
//Menampilkan point start dari line ke-1 dengan GetPointStart
printf("\nMenampilkan point start dari line ke-1 dengan GetPointStart\n");
start1 = GetPointStart(L1);
printf("Point Start : ");
PrintPoint(start1);
//Menampilkan point end dari line ke-1 dengan GetPointEnd
printf("\nMenampilkan point end dari line ke-1 dengan GetPointEnd\n");
end1 = GetPointEnd(L1);
printf("Point End : ");
PrintPoint(end1);
//Menghitung panjang line ke-1 dengan LineLength
printf("\nMenghitung panjang line ke-1 dengan LineLength\n");
printf("Panjang L1 : %.2f\n", LineLength(L1));
//Membuat Line ke-2 dengan CreateHorizontalLine
printf("\nMembuat Line ke-2 dengan CreateHorizontalLine\n");
scanf("%d %d\n", &x, &y); // input atribut point dari user
t = CreatePoint(x,y);
scanf("%d", &panjang);
L2 = CreateHorizontalLine(t,panjang);
//Menampilkan Line ke-2 dengan PrintPoint
printf("Menampilkan Line ke-2 dengan PrintPoint\n");
PrintLine(L2);
//Menghitung panjang line ke-2 dengan LineLength
printf("\nMenghitung panjang line ke-2 dengan LineLength\n");
printf("Panjang L1 : %.2f\n", LineLength(L2));
//Set point end dari line ke-2 dengan SetPointEnd
printf("Set point end dari line ke-2 dengan SetPointEnd\n");
scanf("%d %d", &x, &y); // input atribut point dari user
v = CreatePoint(x,y);
SetPointEnd(v, &L2);
PrintLine(L2);
//Membuat Line ke-3 dengan CreateVerticalLIne
printf("\nMembuat Line ke-3 dengan CreateVerticalLine\n");
w = CreatePoint(5,10);
L3 = CreateVerticalLine(w,0);
PrintLine(L3);
//Cek Line ke-3 dengan IsLine
printf("\nCek Line ke-3 dengan IsLine\n");
if(IsLine(L3)){
	printf("Line");
}else{
	ResetLine(&L3);
}

//Cek Line ke-1 diagonal dengan isDiagonal
printf("\nCek Line ke-1 diagonal dengan isDiagonal\n");
if(IsDiagonal(L1)){
	printf("Diagonal\n");
}else{
	printf("Bukan Diagonal\n");
}

//Mengecek Line terpanjang antara Line ke-1 dan Line ke-2
printf("Titik terpanjang dengan koordinat : ");
CompareLines(L1,L2);

//Transpose Vertical Line ke-1
printf("\nTranspose Vertical Line ke-1\n");
TransposeVerticalLine(&L1);
PrintLine(L1);

//Transpose Horizpntal Line ke-2
printf("\nTranspose Horizontal Line ke-2\n");
TransposeHorizontalLine(&L2);
PrintLine(L2);

//Resize Line ke-1
printf("\nResize Line ke-1\n");
scanf("%d", &panjang2);
ResizeHorizontalLine(&L1,panjang2);
PrintLine(L1);
}

