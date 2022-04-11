#include <stdio.h>
#include <stdlib.h>
#include "Person.h"
#include <string.h>


void ShowMenu(){ 
	printf("==============PROGRAM ANTRIAN BANDARA==============");
	printf("\n1. Tambah antrian");
	printf("\n2. Hapus antrian");
	printf("\n3. Quit");
}

int main(int argc, char *argv[]) {
	ShowMenu();
	Queue q;
	CreateQueue(&q);
	int pilihan, i, finish;
	PERSON P;
	finish = 0;
	address cek;
	do{
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
			printf("\nMasukkan Nama : ");
			scanf("%s", &P.nama);
			printf("\nMasukkan Waktu Datang : ");
			scanf("%d", &P.arrival);
			printf("\nMasukkan Jumlah Koper : ");
			scanf("%d", &P.koper);			
			updateWaktu(&P, q, finish);
			cek = (HEAD(q));
			AddQue(&q, P);
			i++;
			finish = P.finish;	
			if(!IsQueueEmpty(q)){
				while(infofin(HEAD(q)) < infoarr(TAIL(q))) {					
						DelQue(&q, &(info(HEAD(q))));
						i--;					
				}							
				
			}		
			
			CetakInfo(P);
			printf("\n");
			CetakQueue(q);
			ShowMenu();
		}
		
		if(pilihan == 2){
			/* Deque data teratas */
			DelQue(&q, &(info(HEAD(q))));
			i--;
			/* Tampilkan informasi bahwa data terlah berhasil di pop */
			printf("Antrian berhasil dikurangi\n");
			/* Tampilkan isi dari antrian */
			
			CetakQueue(q);
			
			/* Tampilkan jumlah dari antrian */
			printf("\n========== %d (Antrian)==========\n\n", i);	
			/* Tampilkan menu lagi */	
			ShowMenu();
		}
		
		if(pilihan == 3){
			return 0;
		}
		
	}while(pilihan < 3);
	return 0;
	
}
