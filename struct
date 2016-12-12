#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DERS_SAYISI 2

typedef struct Ders{
	char isim[30];
	int kapasite;
	char derslik[10];
	int donem;
}Ders;

void yeniDers(Ders *d, char yIsim[], int yKapasite, char yDerslik[], int yDonem);
void yazdir(Ders *d);

int main(){
	int i;
	Ders dersler[DERS_SAYISI];

	yeniDers(&dersler[0], "Algoritma1", 70, "M107", 1);
	yeniDers(&dersler[1], "Algoritma2", 90, "M108", 2);

	for (i = 0; i < DERS_SAYISI; i++)
	{
		yazdir(&dersler[i]);
	}
	return 0;
}

void yeniDers(Ders *d, char yIsim[], int yKapasite, char yDerslik[], int yDonem){
	strcpy(d->isim, yIsim);
	d->kapasite = yKapasite;
	strcpy(d->derslik, yDerslik);
	d->donem = yDonem;
}

void yazdir(Ders *d){
	printf("Derslik: %s\nDers: %s\nDonem: %d\nOgrenci: %d\n", d->derslik, d->isim, d->donem, d->kapasite);
}
