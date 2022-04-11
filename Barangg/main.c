#include "barang.h"
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	BARANG B;
	char *a,*b, cek;
	
	int x ;
	printf("Nama Barang : ");
	scanf("%s", &a);
	printf("\n");
	printf("Harga Barang : ");
	scanf("%d", &x);
	printf("Member? [Y/N] :");
	isMember(cek);
	B=CreateBarang(&a,x);
	
	
	
	printf("\n");
	printf("====Invoice====\n");
	TampilBarang(B);
	if(isMember){
		printf("\nMendapat diskon 50\n");
	}
	printf("Total Tagihan %d",GetHargaDiskon(B,50));
	printf("\n=============");
	
	return 0;
}

