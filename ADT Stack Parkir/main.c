#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void ShowMenu(){ 
	printf("==== STUDI KASUS PARKIR MOBIL ====");
	printf("\n1. Memasukkan Mobil");
	printf("\n2. Mengeluarkan Mobil");
	printf("\n0. Selesai");
}
void ShowArah(){
	printf("==== ARAH KELUAR MOBIL ====");
	printf("\n1. Kiri");
	printf("\n2. Kanan");
}
/*Prosedur untuk menampilkan menu operasi stack*/

int main() {
	// Menampilkan Menu pada saat program dijalankan 
     ShowMenu(); 
     
	

	// Membuat Stack 
	Stack s,p;
	CreateEmpty(&s);
	CreateEmpty(&p);
	infotype x, plat;
	int pilihan, arah;
	
	do{
		
		// Mengambil input piliham menu dari user 
		printf("\nMasukkan Pilihan anda : ");
		scanf("%d", &pilihan);
		if(pilihan == 1){
				// Ambil input angka dari user 
				printf("Masukkan plat nomor mobil yang akan dimasukkan ke tempat parkir (tanpa spasi) : ");	
				//gets(plat);	
				scanf("%s",&plat);
				//printf("%s\n", &plat);
			if(!IsFull(s)){
				
				// Push angka ke stack 
				Push(&s, plat);
				
				// Print stack 
				printf("\n==========Di dalam area parkir==========\n");
				PrintStack(s);
				
				// Tampilkan menu lagi 
				
			}else{
				printf("\nTempat Parkir Sudah Penuh\n");
			}
			ShowMenu();
		}
		// Jika user memilih menu Push			
			
		if(pilihan == 2){
			// Ambil input angka dari user 
			printf("\nMasukkan plat nomor mobil yang akan dikeluarkan dari tempat parkir (tanpa spasi) : ");	
			scanf("%s", &plat);
			if(find(s,plat)){
				do{
					ShowArah();
					printf("\nMasukkan arah keluar mobil : ");
					scanf("%d", &arah);
						
				}while(arah != 1 && arah !=2);
				
				if(checkPop(s,plat)){
					Pop(&s, &x);
					printf("\n==========Di dalam area parkir==========\n");
					PrintStack(s);
				}else{
					cekArah(arah);
					MoveEl(&p, &s, &plat);
				}
			}else{
				printf("\nNomor plat mobil tidak ada\n");
			}
			// Pop data teratas
			
			
			// Tampilkan informasi bahwa data terlah berhasil di pop
			//printf("Berhasil di Pop\n");
				
			// Tampilkan menu lagi	
			ShowMenu();
		}
		
		if(pilihan == 0){
			// Tampilkan isi dari stack
			printf("\nMobil di dalam area parkir :\n");
			PrintStack(s);
			
			// Tampilkan jumlah dari stack 
			printf("\n========== %d (Mobil)==========\n\n", Top(s));
			
			// Tampilkan menu lagi 	
			ShowMenu();
		}else{
			//printf("Kode operasi salah\n");
		}
	}while(pilihan != 0);
	
	return 0;
}



/*
int main(){	
	Stack s, p;
	CreateEmpty(&s);
	CreateEmpty(&p);
	infotype x = "2222";
	
	printf("Ini stack s\n");
	Push(&s, "1111");
	Push(&s, "2222");
	Push(&s, "3333");
	Push(&s, "4444");
	PrintStack(s);
	
	
	printf("\nIni stack p\n");
	MoveEl(&p, &s, &x);
	PrintStack(p);
	
	printf("\nIni stack s\n");
	PrintStack(s);
	return 0;
	

}*/
