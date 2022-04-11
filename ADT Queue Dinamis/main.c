#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void ShowMenu(){ 
	printf("==== PRAKTIKUM Queue DINAMIS ====");
	printf("\n1. Enque");
	printf("\n2. Deque");
	printf("\n3. Print Queue");
	printf("\n4. Quit");
}
/*Prosedur untuk menampilkan menu operasi stack*/

int main() {
	/* Menampilkan Menu pada saat program dijalankan */
     ShowMenu(); 
     
	

	/* Membuat Stack */
	Queue q;
	CreateQueue(&q);
	
	int pilihan, nilai_stack,i;
	do{
		/*Mengambil input piliham menu dari user */
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		
		/* Jika user memilih menu Push */
		if(pilihan == 1){
			/* Ambil input angka dari user */
			printf("Masukkan nilai yang akan dimasukkan ke queue : ");		
			scanf("%d", &nilai_stack);
			
			/* Push angka ke stack */
			AddQue(&q, nilai_stack);
			i++;
			/* Tampilkan menu lagi */
			ShowMenu();
		}
		
		if(pilihan == 2){
			/* Pop data teratas */
			DelQue(&q, &(info(HEAD(q))));
			i--;
			/* Tampilkan informasi bahwa data terlah berhasil di pop */
			printf("Berhasil di Deque");
				
			/* Tampilkan menu lagi */	
			ShowMenu();
		}
		
		if(pilihan == 3){
			/* Tampilkan isi dari stack */
			printf("\nIsi dari Queue :\n");
			CetakQueue(q);
			
			/* Tampilkan jumlah dari stack */
			printf("\n========== %d (Antrian)==========\n\n", i);
			
			/* Tampilkan menu lagi */	
			ShowMenu();
		}
	}while(pilihan < 4);
	
	return 0;
}
