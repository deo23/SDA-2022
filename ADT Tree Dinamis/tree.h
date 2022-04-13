/*
    Program         : tree.h
    Deskripsi       : Header ADT Tree
    Nama /Author    : Muhammad Deo Audha Rizki
    Tanggal/versi   : 07 April 2022/1.0
    Compiler        : 
*/
#ifndef nbtree_d_H
#define nbtree_d_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct nbTreeNode *address;

typedef struct  { 
  char jabatan[50];
  char nama[50]; 
} nbType;

typedef struct { 
  address root; 
} nbTree;

typedef struct nbTreeNode{
  address parent;
  address firstChild; 
  address nextBrother; 
  nbType data;
}ElmtTree;

/* ---------------- Konstruktor Tree ---------------- */
void initTree(nbTree *x);
//Membuat tree kosong (X.root=NULL)

void CreateTree(nbTree *T, nbType data);
//Membuat tree dengan root data

/* ---------------- Alokasi node baru Tree ---------------- */
address initNode(nbType X);
//Alokasi untuk membuat node baru

/* ---------------- Operasi-operasi Tree ---------------- */
void addChild(address *Root, nbType data);
// Menambah element sebagai child dari parent Root

void addSibling(address *Root, nbType data);
// Menambah element sebagai sibling dari node Root

void findChild(address Root);
//Mencari child dari node Root

void findParent(address Root);
//Mencari parent dari node Root

void findGrandParent(address Root);
//Mencari grandparent dari node Root
address Search(address root, char* src);
//Mencari data pada tree

/* ---------------- PRINT TREE ---------------- */
void PrintPreOrder(address root);


#endif

