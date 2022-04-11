#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void ShowMenu(){ 
	printf("==============PROGRAM ANTRIAN PENCUCIAN MOBIL==============");
	printf("\n1. Tambah antrian mobil");
	printf("\n2. Kurangi antrian mobil");
	printf("\n3. Lihat antrian");
	printf("\n4. Quit");
}

void TipeMobil(){
	printf("\n==========================Tipe Mobil==========================\n");
	printf("1. Mobil Kecil : 20 menit service, 1 menit jeda (Contoh : Ceria/Karimun/Agya)\n");
	printf("2. SUV : 30 menit service, 2 menit jeda (Contoh : Avanza)\n");
	printf("3. SUV-2 : 45 menit service, 4 menit jeda (Contoh : Innova/CRV/Pajero)\n");
	printf("4. Mini : 60 menit service, 5 menit jeda (Contoh : Alphard, Grand Max)\n");
	printf("5. Truck-1 : 80 menit service, 6 menit jeda (Contoh : Angkel)\n");
	printf("6. Truck-2 : 100 menit service, 8 menit jeda (Contoh : Truck Normal)\n");
	printf("7. Truck-3 : 120 menit service, 9 menit jeda (Contoh : Besar)\n");
	printf("8. Bus : 125 menit service, 10 menit jeda (Contoh : Bus)\n");
	
}


int main(int argc, char *argv[]) {
	
	ShowMenu();
	Queue q;
	CreateQueue(&q);
	int pilihan, jenis_mobil, i, finish;
	MOBIL M;
	finish = 0;
	do{
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
			TipeMobil();
			printf("\nSilahkan Masukkan Tipe Mobil : ");
			scanf("%d", &jenis_mobil);
			M = JenisMobil(jenis_mobil);		
			printf("\nSilahkan Masukkan Waktu Tiba : ");
			scanf("%d", &M.arrival);
			updateWaktu(&M, q, finish);	
			finish = M.finish;		
			AddQue(&q, M);
			i++;
			ShowMenu();	
				
		}
		
		if(pilihan == 2){
			/* Pop data teratas */
			DelQue(&q, &(info(HEAD(q))));
			i--;
			/* Tampilkan informasi bahwa data terlah berhasil di pop */
			printf("Antrian berhasil dikurangi");
				
			/* Tampilkan menu lagi */	
			ShowMenu();
		}
		
		if(pilihan == 3){
			/* Tampilkan isi dari stack */
			printf("\nIsi Antrian Mobil :\n");
			CetakQueue(q);
			
			/* Tampilkan jumlah dari stack */
			printf("\n========== %d (Antrian)==========\n\n", i);
			
			/* Tampilkan menu lagi */	
			ShowMenu();
		}
		
		if(pilihan == 4){
			return 0;
		}
	}while(pilihan < 4);
}

