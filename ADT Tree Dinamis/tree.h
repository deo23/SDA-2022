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


typedef struct nbTreeNode *nbAddr;

typedef struct  { 
  char jabatan[50];
  char nama[50]; 
} nbType;

typedef struct { 
  nbType root; 
} nbTree;

typedef struct nbTreeNode{
  nbAddr parent;
  nbAddr firstChild; 
  nbAddr nextBrother; 
  nbType data;
}ElmtTree;

/* ---------------- Konstruktor Tree ---------------- */
void initTree(nbAddr *x);
//Membuat tree kosong (X.root=NULL)

/* ---------------- Alokasi node baru Tree ---------------- */
nbAddr initNode(nbType X);
//Alokasi untuk membuat node baru

/* ---------------- Operasi-operasi Tree ---------------- */
nbAddr InsertNode(nbAddr *tRoot, nbAddr parent, nbType X);
// Menambah element pada node parent

nbAddr SearchNode(nbAddr root, nbType src);
// Mencari node dengan info ttn dan mengembalikan addressnya

int Depth(nbAddr root);
// Mengukur kedalaman suatu node dari root


/* ---------------- TRAVERSAL Tree ---------------- */
void nbPost(nbAddr root); // Postorder traversing
void nbPre(nbAddr root); // Preorder traversing
//void nbIn(nbAddr root); // Inorder traversing
void nbLevelOrder(nbAddr root,int curLevel, int desLevel); // Levelorder traversing

/* ---------------- PRINT TREE ---------------- */
void nbPrint(nbAddr node, char tab[]);

#endif

