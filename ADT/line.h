#include "boolean.h"
#include "point.h"
#ifndef LINE_H
#define LINE_H
/* definisi type data */
typedef struct
{ POINT start;
POINT end;
} LINE; // type LINE


LINE CreateLine(POINT pStart, POINT pEnd);
/*Fungsi untuk membuat LINE dari 2 nilai Point dari modul pemanggil
pStart : Titik awal bertipe POINT
pEnd : Titik akhir bertipe POINT
*/

LINE CreateHorizontalLine(POINT start, int lenghtX);
/*Fungsi untuk membuat LINE secara horizontal
pStart : Titik awal bertipe POINT
lengthX : panjang nilai X bertipe int
*/

LINE CreateVerticalLine(POINT start, int lenghtY);
/*Fungsi untuk membuat LINE secara vertikal
start : Titik awal bertipe POINT
lengthY : panjang nilai Y bertipe int
*/

void PrintLine(LINE line);
/*Prosedur untuk menampilkan Line ke layar
tampilkan nilai X dan Y dari Titik awal serta nilai X dan Y dari
Titik Akhir
*/

void SetPointStart(POINT pStart, LINE *line);
/*Prosedur untuk memberikan nilai Titik awal bertipe POINT pada

sebuah Line*/

POINT GetPointStart(LINE line);
/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line*/

void SetPointEnd(POINT pEnd, LINE *line);
/*Prosedur untuk memberikan nilai Titik akhir bertipe POINT pada
sebuah Line*/

POINT GetPointEnd(LINE line);
/*Fungsi untuk mendapatkan nilai Titik awal bertipe POINT dari
sebuah Line */

boolean IsLine(LINE line);
/*Fungsi untuk mengecek apakah nilai parameter line adalah sebuah
LINE atau bukan
Fungsi ini mengembalikan nilai true jika nilai titik awal (x,y)
!= nilai titik akhir (x,y)
dengan asumsi : jika nilai titik awal (x,y) = nilai titik akhir
(x,y) maka bukanlah sebuah line, akan tetapi titik yang bertumpuk
*/

boolean IsHorizontalLine(LINE line);
/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai y pada titik awal
= nilai y pada titik akhir
*/

boolean IsVerticalLine(LINE line);
/*Fungsi untuk mengecek apakah sebuah Line horizontal atau tidak
Fungsi ini mengembalikan nilai true jika nilai x pada titik awal
= nilai x pada titik akhir
*/

double LineLength(LINE line);
/*Fungsi untuk menghitung panjang dari sebuah line dan
mengembalikan nilai integer
panjang dihitung dari nilai titik awal dan titik akhirnya
*/

void ResetLine(LINE *line);
/*Prosedur untuk mereset Line menjadi nilai null*/


boolean IsDiagonal(LINE line);
/*Fungsi untuk mengecek apakah sebuah line diahonal atau tidak
Fungsi ini mengembalikan nilai true*/

void CompareLines(LINE line1, LINE line2);
/*Prosedur untuk mengecek mana garis yang terpanjang
Garis terpanjang ditampolkan ke layar*/

void TransposeVerticalLine(LINE *line);
/*Prosedur Melakukan transpose Line dari horizontal ke vertical.*/

void TransposeHorizontalLine(LINE* line);
/*Prosedur Melakukan transpose Line dari vertical ke horizontal.*/

void ResizeHorizontalLine(LINE *line, int panjang);
/*Prosedur untuk menambah panjang line yang berbentuk horizontal*/
#endif
