#include <stdio.h>
#include <string.h>
#include "tree.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(){
   /* DEKLARASI*/
  nbTree T;
  nbType data;
  address temp;
  

  // Kepala Pusat (root) - Ujang Kartiwa
  strcpy(data.nama, "Ujang Kartiwa");
  strcpy(data.jabatan, "Kepala Pusat");
  CreateTree(&T,data);

  // Kepala Bagian Perencanaan - Engkos Koswara
  strcpy(data.nama, "Engkos Koswara");
  strcpy(data.jabatan, "Kepala Bagian Perencanaan");
  addChild(&T.root,data);

  // Kepala Sub Bagian Anggaran - Tati Sulastri
  strcpy(data.nama, "Tati Sulastri");
  strcpy(data.jabatan, "Kepala Sub Bagian Anggaran");
  addChild(&T.root->firstChild,data);

  // Staff - Muktadi
  strcpy(data.nama, "Muktadi");
  strcpy(data.jabatan, "Staff");
  addChild(&T.root->firstChild->firstChild,data);

  // Staff - Hartanto Utomo
  strcpy(data.nama, "Hartanto Utomo");
  strcpy(data.jabatan, "Staff");
  addSibling(&T.root->firstChild->firstChild->firstChild,data);

  // Kepala Sub Bagian Pendataan - Irvan Susilo
  strcpy(data.nama, "Irvan Susilo");
  strcpy(data.jabatan, "Kepala Sub Bagian Pendataan");
  addSibling(&T.root->firstChild->firstChild,data);
  
  // Staff - Candra Dimuka
  strcpy(data.nama, "Candra Dimuka");
  strcpy(data.jabatan, "Staff");
  addChild(&T.root->firstChild->firstChild->nextBrother,data);

  // Kepala Sub Bagian Evaluasi - Evi Sukaesih
  strcpy(data.nama, "Evi Sukaesih");
  strcpy(data.jabatan, "Kepala Sub Bagian Evaluasi");
  addSibling(&T.root->firstChild->firstChild->nextBrother,data);

  // Staff - Kartono
  strcpy(data.nama, "Kartono");
  strcpy(data.jabatan, "Staff");
  addChild(&T.root->firstChild->firstChild->nextBrother->nextBrother,data);

  //------------------------

  // Kepala Bagian SDM - Hoerul Anam
  strcpy(data.nama, "Hoerul Anam");
  strcpy(data.jabatan, "Kepala Bagian SDM");
  addSibling(&T.root->firstChild,data);

  // Kepala Sub Bagian Kepegawaian - Sambas Nugroho
  strcpy(data.nama, "Sambas Nugroho");
  strcpy(data.jabatan, "Kepala Sub Bagian Kepegawaian");
  addChild(&T.root->firstChild->nextBrother,data);

  // Staff - Markonah
  strcpy(data.nama, "Markonah");
  strcpy(data.jabatan, "Staff");
  addChild(&T.root->firstChild->nextBrother->firstChild,data);

  // Staff - Jaelani Supri Utama
  strcpy(data.nama, "Jaelani Supri Utama");
  strcpy(data.jabatan, "Staff");
  addSibling(&T.root->firstChild->nextBrother->firstChild->firstChild,data);

  // Staff - Ukar Mustopa
  strcpy(data.nama, "Ukar Mustopa");
  strcpy(data.jabatan, "Staff");
  addSibling(&T.root->firstChild->nextBrother->firstChild->firstChild->nextBrother,data);

  // Kepala Sub Bagian Tata Laksana - Mujani Gani
  strcpy(data.nama, "Mujani Gani");
  strcpy(data.jabatan, "Kepala Sub Bagian Tata Laksana");
  addSibling(&T.root->firstChild->nextBrother->firstChild,data);

  // Staff - Marcellino
  strcpy(data.nama, "Marcellino");
  strcpy(data.jabatan, "Staff");
  addChild(&T.root->firstChild->nextBrother->firstChild->nextBrother,data);

  // Staff - Opik Taufik
  strcpy(data.nama, "Opik Taufik");
  strcpy(data.jabatan, "Staff");
  addSibling(&T.root->firstChild->nextBrother->firstChild->nextBrother->firstChild,data);

  //----------------------

  // Kepala Bagian Keuangan - Dana Sukirman
  strcpy(data.nama, "Dana Sukirman");
  strcpy(data.jabatan, "Kepala Bagian Keuangan");
  addSibling(&T.root->firstChild->nextBrother,data);

  // Kepala Sub Bagian Pelaksana Keuangan - Noviyanti
  strcpy(data.nama, "Noviyanti");
  strcpy(data.jabatan, "Kepala Sub Bagian Pelaksana Keuangan ");
  addChild(&T.root->firstChild->nextBrother->nextBrother,data);

  

  /* Print Node*/
  printf("\n Isi Tree : \n");
  
  // PreOrder
  printf(" PreOrder :\n");
  printf(" =================\n");
  PrintPreOrder(T.root);
  
  
  // Mencari Atasan - Kartono
  temp = Search(T.root, "Kartono");
  findParent(temp);

  // Mencari Bawahan - Sambas Nugroho
  temp = Search(T.root, "Sambas Nugroho");
  findChild(temp);
  
  // Mencari Grand Parent - Markonah
  temp = Search(T.root, "Opik Taufik");
  findGrandParent(temp);
  
  return 0;
}
