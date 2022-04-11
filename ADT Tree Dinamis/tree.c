/*
    Program         : tree.c
    Deskripsi       : Header ADT Tree
    Nama /Author    : Muhammad Deo Audha Rizki
    Tanggal/versi   : 07 April 2022/1.0
    Compiler        : 
*/

#include <malloc.h>
#include "tree.h"

void initTree(nbAddr *x){
	(*x)=NULL;
}

nbAddr initNode(nbType X){
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

nbAddr InsertNode(nbAddr *tRoot, nbAddr parent, nbType X){
	
	nbAddr newNode, temp;
	
	newNode=initNode(X);
	if (newNode !=NULL){ //Jika penciptaan node baru berhasil
		if (parent==NULL) //JIka belum terdapat root
			*tRoot=newNode;
		else{
			temp=parent;
			if (temp->firstChild != NULL){
				temp=temp->firstChild;
				while(temp->nextBrother!=NULL)
					temp=temp->nextBrother;
				temp->nextBrother=newNode;
			}else
				temp->firstChild=newNode;
			newNode->parent=parent;
		}
	}
	return(newNode);
}

void nbPrint(nbAddr node, char tab[]){
	char tempTab[255];
	strcpy(tempTab, tab);
	strcat(tempTab, "-");
	if (node!=NULL){
		printf("%s%s\n",tab,node->data.nama);
		nbPrint(node->firstChild,tempTab);
		nbPrint(node->nextBrother,tab);
	}
}


