/* File main.c untuk Main Driver ADT Stack */ 
#include <stdio.h>
#include <stdlib.h>
#include "stackt.h"

void ShowMenu(){ 
	printf("==== PRAKTIKUM STACK ====");
	printf("\n1. Push");
	printf("\n2. Pop");
	printf("\n3. Print Stack");
	printf("\n4. Quit");
}
/*Prosedur untuk menampilkan menu operasi stack*/

int main() {
	/* Menampilkan Menu pada saat program dijalankan */
     ShowMenu(); 
     
	

	/* Membuat Stack */
	Stack s;
	CreateEmpty(&s);
	infotype x;

	int pilihan, nilai_stack;
	do{
		/*Mengambil input piliham menu dari user */
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		
		/* Jika user memilih menu Push */
		if(pilihan == 1){
			/* Ambil input angka dari user */
			printf("Masukkan nilai yang akan dimasukkan ke stack : ");		
			scanf("%d", &nilai_stack);
			
			/* Push angka ke stack */
			Push(&s, nilai_stack);
			
			/* Tampilkan menu lagi */
			ShowMenu();
		}
		
		if(pilihan == 2){
			/* Pop data teratas */
			Pop(&s, &x);
			
			/* Tampilkan informasi bahwa data terlah berhasil di pop */
			printf("Berhasil di Pop");
				
			/* Tampilkan menu lagi */	
			ShowMenu();
		}
		
		if(pilihan == 3){
			/* Tampilkan isi dari stack */
			printf("\nIsi dari Stack :\n");
			PrintStack(s);
			
			/* Tampilkan jumlah dari stack */
			printf("\n========== %d (Tumpukan)==========\n\n", Top(s));
			
			/* Tampilkan menu lagi */	
			ShowMenu();
		}
	}while(pilihan < 4);
	
	return 0;
}


