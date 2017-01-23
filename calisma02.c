// Turkalp Burak KAYRANCIOGLU
// bkayranci

#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef struct ogrenci{
		int yas;
		int puan;
	}ogrenci;

int kacKisiCbv(){
	int don;
	
	printf("\nKac kisi girmek istiyorsun: ");
	scanf("%d",&don);
	
	return don;
}

void kacKisiCbr(int *sayi){
	int deger;
	
	printf("\nKac kisi girmek istiyorsun: ");
	
	scanf("%d",&deger);
	*sayi=deger;
	
	//scanf("%d",&*sayi);
}

void doldur(ogrenci *dizi,int sayi){
	int i;
	for(i=0;i<sayi;i++){
		dizi[i].yas=1+rand()%20;	// 1 den 20 ye kadar 1 ve 20 dahil sayi olusturur.
		dizi[i].puan=1+rand()%100;	// 1 den 100 e kadar 1 ve 100 dahil sayi olusturur.
	}
}


void yazdir(ogrenci *dizi,int sayi){
	int i;
	for(i=0;i<sayi;i++){
		printf("\n#%d.Ogrenci\nYasi: %d\nPuani: %d\n\n",i+1,dizi[i].yas,dizi[i].puan);
	}
}


void yasiKucukOlanlar(int kactanKucuk, ogrenci *dizi,int sayi,ogrenci *yeniDizi){
	int i,j=0;
	for(i=0;i<sayi;i++){
		if(dizi[i].yas<kactanKucuk){
			printf("\n#%d. Ogrencinin yasi %d den kucuktur.",i+1,kactanKucuk);	// Hangilerinin kucuk oldugunu ekrana yazdirdim.
			
			yeniDizi[j].yas=dizi[i].yas;	//Hangilerinin kucuk oldugunu yeni diziye(direk main icine) kopyaladim.
			yeniDizi[j].puan=dizi[i].puan;	//Hangilerinin kucuk oldugunu yeni diziye(direk main icine) kopyaladim.
			j++;
		}
	}
}

int main(){
		
	
	int sayi;
	
	//sayi=kacKisiCbv();	// Call by Value ile sayiyi belirle. Fonksiyon girilen degeri dondurur. 3 gibi 5 gibi, ama main icindeki sayi degiskeninin adresini bilmez bunun icin sayi degiskenini dondurdugumuz degere esitleyelim.
	kacKisiCbr(&sayi);	// Call by Reference ile sayiyi belirle. Fonksiyon bisi dondurmez, direk main in icindeki sayi degiskenini degistirir.
	
	printf("\n%d Kisi Gireceksiniz\n\n",sayi);

	ogrenci dizi[sayi];
	
	doldur(&dizi,sayi);	// Call by Reference ile olusturdugum dizinin icini rastgele doldurur. Main in icindeki dizinin icini direk degistirir
	yazdir(&dizi,sayi);
	
	ogrenci yeniDizi[sayi];
	yasiKucukOlanlar(4,&dizi,sayi,&yeniDizi); // Yasin kactan kucuk olacagini en bastaki deger olarak yolladim. Ona gore fonksiyonda ilk deger olarak alacagim. main icindeki yeniDizi ye yazacagim.
	printf("\n-------------\n");
	yazdir(&yeniDizi,sayi);	// yeni dizinin boyutunu bilmedigim icin sayi kadar yazdiracagim. yani dizinin icinde 3 tanesi kucuk ama ben 5 tane yazdirmak istiyorum(olmayan degerler icin sacma degerler yazacak). Bunun icin onceki calismada hem listeyi hem de boyutunu dondurmek icin bir struct olusturmustuk. Oyle bir sey yapilabilir.
	
	return 0;
}
