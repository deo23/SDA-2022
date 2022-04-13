/*
    Program         : tree.c
    Deskripsi       : Header ADT Tree
    Nama /Author    : Muhammad Deo Audha Rizki
    Tanggal/versi   : 07 April 2022/1.0
    Compiler        : 
*/

#include <malloc.h>
#include "tree.h"

void initTree(nbTree *x){
	(*x).root=NULL;
}

void CreateTree(nbTree *T, nbType data){
  address P;
  P = (address)malloc(sizeof(ElmtTree));
  strcpy(P->data.nama,data.nama);
  strcpy(P->data.jabatan,data.jabatan);
  P->firstChild = NULL;
  P->nextBrother = NULL;
  (*T).root = P;
}

address initNode(nbType X){
	ElmtTree *newNode;
	newNode=(ElmtTree*) malloc(sizeof(ElmtTree));
	if (newNode != NULL){
		newNode->parent=NULL;
		newNode->data=X;
		newNode->firstChild=NULL;
		newNode->nextBrother=NULL;
	}
	return newNode;
}

void addChild(address *Root, nbType data){
  if((*Root)->firstChild == NULL){
    address P;
    P = (address)malloc(sizeof(ElmtTree));
    strcpy(P->data.nama,data.nama);
    strcpy(P->data.jabatan,data.jabatan);
    P->parent = (*Root);
    P->firstChild = NULL;
    P->nextBrother = NULL;
    (*Root)->firstChild = P;
  }
  else{
    printf("Root sudah memiliki anak");
  }
}

void addSibling(address *Root, nbType data){
  if((*Root)->nextBrother == NULL){
    address P;
    P = (address)malloc(sizeof(ElmtTree));
    strcpy(P->data.nama,data.nama);
    strcpy(P->data.jabatan,data.jabatan);
    P->parent = (*Root)->parent;
    P->firstChild = NULL;
    P->nextBrother = NULL;
    (*Root)->nextBrother = P;
  }
  else{
    printf("Root sudah memiliki sibling");
  }
}

void PrintPreOrder(address root){
  if(root != NULL){
    printf(" %s - ",root->data.nama);
    printf(" %s\n",root->data.jabatan);
    PrintPreOrder(root->firstChild);
    PrintPreOrder(root->nextBrother);
  }
}

void ReadElement(nbType *input){
  fflush(stdin);
  scanf("%[^\n]c",&input->nama);
  printf(" Jabatan : ");
  fflush(stdin);
  scanf("%[^\n]c",&input->jabatan);
}

void findChild(address Root){
	address bro;
	bro = Root->firstChild;
	printf(" - Child dari %s adalah",Root->data.nama);
	do{
		
		printf(" %s,",bro->data.nama);
		bro = bro->nextBrother;	
		if(bro->nextBrother == NULL){
			printf(" %s\n",bro->data.nama);
		}
	}while(bro->nextBrother != NULL);
}


void findParent(address Root){
  printf(" - Parent dari %s adalah %s\n",Root->data.nama,Root->parent->data.nama);
}

void findGrandParent(address Root){
  printf(" - GrandParent dari %s adalah %s\n",Root->data.nama,Root->parent->parent->data.nama);
}

void findSibling(address Root){
  printf(" - Sibling dari %s adalah %s\n",Root->data.nama,Root->nextBrother->data.nama);
}

address Search(address root, char* src){
	address nSrc;
	if (root!=NULL){
		int compare = strcmp(root->data.nama,src);
		if (compare == 0){
			return root;
		}		
		else{
			nSrc=Search(root->firstChild,src);
			if (nSrc==NULL){
				return Search(root->nextBrother,src);
			}	
			else{
				return nSrc;	
			}	
		}
	}
	return NULL;
}

