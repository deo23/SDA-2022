#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "string.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Stack s;	
	char kata[10];
	int i;
	CreateEmpty(&s);
	printf("=============PROGRAM PENGECEKAN PALINDROM=============\n");
	printf("Silahkan masukkan kata : ");
	scanf("%s",&kata);
	for(i = 0; i<strlen(kata);i++){
		Push(&s,kata[i]);
	}
	
	if(cekPalindrom(s)){
		printf("Ya, kata %s adalah palindrom", kata);
	}else{
		printf("Oops, kata %s bukan palindrom", kata);
	}
	return 0;
}
