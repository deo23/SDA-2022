// Program : Point.c
// Deskripsi : Body ADT POINT
// Created : Muhammad Deo Audha Rizki
// Modified :
// Tanggal : 3 Maret 2022
#include <stdio.h>
#include <math.h>
#include "point.h"
#include "boolean.h"
#include "line.h"

LINE CreateLine(POINT pStart, POINT pEnd){
/*Fungsi untuk membuat LINE dari 2 nilai Point dari modul pemanggil
pStart : Titik awal bertipe POINT
pEnd : Titik akhir bertipe POINT
*/
LINE L;
L.start = pStart;
L.end = pEnd;
return L;
}

LINE CreateHorizontalLine(POINT start, int lengthX){
/*Fungsi untuk membuat LINE secara horizontal
pStart : Titik awal bertipe POINT
lengthX : panjang nilai X bertipe int
*/
LINE L;
POINT end;

end = start;
end.x += lengthX;
L.start = start;
L.end = end;
return L;
}

LINE CreateVerticalLine(POINT start, int lengthY){
/*Fungsi untuk membuat LINE secara vertikal
start : Titik awal bertipe POINT
lengthY : panjang nilai Y bertipe int
*/
LINE L;
POINT end;

end = start;
end.y += lengthY;
L.start = start;
L.end = end;
return L;
}

void PrintLine(LINE line){
/*Prosedur untuk menampilkan Line ke layar
tampilkan nilai X dan Y dari Titik awal serta nilai X dan Y dari
Titik Akhir
*/
printf("Titik awal (%d, %d)", line.start.x, line.start.y);
printf(" Titik akhir (%d, %d)", line.end.x, line.end.y);
}

void SetPointStart(POINT pStart, LINE *line){ 
/*Prosedur untuk memberikan nilai Titik awal bertipe POINT pada
sebuah Line*/
(*line).start = pStart;
}

POINT GetPointStart(LINE line){
/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line*/
return line.start;
}

void SetPointEnd(POINT pEnd, LINE *line){
/*Prosedur untuk memberikan nilai Titik akhir bertipe POINT pada
sebuah Line*/
(*line).end = pEnd;
}

POINT GetPointEnd(LINE line){
/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line */
return line.end;
}

boolean IsLine(LINE line){
/*Fungsi untuk mengecek apakah nilai parameter line adalah sebuah
LINE atau bukan
Fungsi ini mengembalikan nilai true jika nilai titik awal (x,y)
!= nilai titik akhir (x,y)
dengan asumsi : jika nilai titik awal (x,y) = nilai titik akhir
(x,y) maka bukanlah sebuah line, akan tetapi titik yang bertumpuk
*/
if((line.start.x != line.end.x) && (line.start.y != line.end.y)){
	return true;
}else{
	return false;
}
}

boolean IsHorizontalLine(LINE line){
/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai x pada titik awal
= nilai x pada titik akhir
*/
if(line.start.y == line.end.y){
	return true;
}else{
	return false;
}
}

boolean IsVerticalLine(LINE line){
/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai x pada titik awal
= nilai x pada titik akhir
*/
if(line.start.x == line.end.x){
	return true;
}else{
	return false;
}
}

double LineLength(LINE line){
/*Fungsi untuk menghitung panjang dari sebuah line dan
mengembalikan nilai integer
panjang dihitung dari nilai titik awal dan titik akhirnya
*/
Jarak(line.start,line.end);
}

void ResetLine(LINE *line){
/*Prosedur untuk mereset Line menjadi nilai null*/
(*line).start.x= NULL;
(*line).start.y= NULL;
(*line).end.x= NULL;
(*line).end.y= NULL;
}

boolean IsDiagonal(LINE line){
/*Fungsi untuk mengecek apakah sebuah line diahonal atau tidak
Fungsi ini mengembalikan nilai true*/
int X,Y;
X = abs(line.start.x - line.end.x);
Y = abs(line.start.y - line.end.y);

if(X == Y){
	return true;
}else{
	return false;
}
}

void CompareLines(LINE line1, LINE line2){
/*Prosedur untukk mengecek mana garis yang terpanjang
Garis terpanjang ditampolkan ke layar*/
if(LineLength(line1) > LineLength(line2)){
	PrintLine(line1);
}else if(LineLength(line1) < LineLength(line2)){
	PrintLine(line2);
}else{
	printf("Panjang kedua garis sama");
}
}

void TransposeVerticalLine(LINE *line){
    if(IsVerticalLine(*line)){
    int panjang = LineLength(*line);
    (*line).end.y = (*line).start.y;
    (*line).end.x = ((*line).start.x + panjang);
    
    }else {
        return;
    }
    
}

void TransposeHorizontalLine(LINE *line){
    if(IsVerticalLine(*line)){
    int panjang = LineLength(*line);
    (*line).end.x = (*line).start.x;
    (*line).end.y = ((*line).start.y + panjang);
    
    }else {
        return;
    }
    
}

void ResizeHorizontalLine(LINE *line, int panjang){
/*Prosedur untuk menambah panjang line yang berbentuk horizontal*/
if(IsHorizontalLine(*line)){
	(*line).end.x += panjang;
}else{
	return;
}
}
