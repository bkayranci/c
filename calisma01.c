// Turkalp Burak KAYRANCIOGLU
// bkayranci

#include <stdio.h>
#include <string.h>
#include <conio.h>

// Ogrenci Dizisi Icın Gerekli
typedef struct listeYapisi{
		int yas;
	}listeYapisi;

// Rastgele Olusturulacak Ogrenci Sayisini Dondurur
int kacKisiGirmekIstiyorsun(){
	int dondur;
	printf("Kac kisi girmek istediginizi girin: ");
	scanf("%d",&dondur);
	return dondur;
}

// Rastgele Ogrenci Olusturur ve Direk Main Icındeki ogrenci Dizisine Yazar
void rastgeleDoldur(listeYapisi *ogrenci,int ogrenciSayisi){
	int i;
	for(i=0;i<ogrenciSayisi;i++){
		ogrenci[i].yas=1+rand()%20;	// 1-20 arasi rastgele bir deger al. 1 ve 20 dahildir.
	}
}

// Gelen Liste Adreslerini ve Liste Boyutlarini Ekrana Yazar
void yazdir(listeYapisi *ogrenci,int ogrenciSayisi){
	int i;
	for(i=0;i<ogrenciSayisi;i++){
		printf("%d.Ogrenci\nYas: %d\n\n",i+1,ogrenci[i].yas);
	}
}

// Yeni Olusturacagim Listeyi ve Listenin Boyutunu Birlikte Dondurmek Icin Gerekli
typedef struct yeniListeYapisi{
	listeYapisi *yeniOnIkidenKucuk;	// 12den kucuklerin sayisini henuz bilmiyorum. Eger 5 tane olsaydi yeniOnIkidenKucuk[5] diye olusturacaktim. Ama simdi sadece pointerla olusturup daha sonra malloc ile yer acacagim.
	int boyut;	// 12 yasindan kucuklerin sayisini tutar.
}yeniListeYapisi;

yeniListeYapisi onIkidenKucukler(listeYapisi *ogrenci,int ogrenciSayisi){
	int i,onIkidenKucukKacTane=0;
	
	// 12 Yasindan Kucuk Olanlarin Sayisini Belirler ve onIkidenKucukKacTane degiskeniyle bunu bizim icin tutar.
	for(i=0;i<ogrenciSayisi;i++){
		if(ogrenci[i].yas<12){
			onIkidenKucukKacTane+=1;
		}
	}
	
	yeniListeYapisi dondur;	// Yeni liste yapisiyla dondurmek istedigimiz listeyi ve boyutunu tutacak bir degisken tanimladik. Bu degiskenin elemanlari boyut ve Liste yapisinda yeniOnIkidenKucuk degiskeni ancak yeniOnIkidenKucuk degiskeni icin yer acilmamis.
	
	dondur.yeniOnIkidenKucuk=(listeYapisi *)malloc(onIkidenKucukKacTane*sizeof(listeYapisi));	// yeniOnIkidenKucuk icin yer aciyorum. Malloc un basindaki casting (listeYapisi *) olan yer icin tam emin degilim.
			
	dondur.boyut=onIkidenKucukKacTane;	// Artik yeni olusturdugumuz listenin boyutunu dondurecek degere listemizin boyutunu tutan degeri esitleyelim. Liste boyutunu onIkidenKucukKacTane degiskeni tutuyor. 
	
	int j=0;
	// 12 den Kucuk Olan Kisileri Dondurecegimiz Degiskenin Listesine Yani Yeni Listeye Esitliyoruz.
	for(i=0;i<ogrenciSayisi;i++){
		if(ogrenci[i].yas<12){
			dondur.yeniOnIkidenKucuk[j].yas=ogrenci[i].yas;
			j++;
		}
	}
	
	return dondur;	// Dondur degiskenimiz bizim icin hem 12 yasindan kucuklerin bir listesini hemde 12 yasindan kucuklerin boyutunu tutuyor. Bizde bu degeri donduruyoruz.
}

int main(){
	int kacKisi;
	
	kacKisi=kacKisiGirmekIstiyorsun();	// Kac kisi girilecegini belirler
	
	listeYapisi ogrenci[kacKisi];	// Rastgele olusturulan liste icin degisken
	yeniListeYapisi onIkidenKucuklerOgrenciler;	// Yasi 12den kucuk liste icin degisken
	
	rastgeleDoldur(ogrenci,kacKisi);	// Ogrenci dizisi rastgele doldurulur. Call by reference ile fonksiyon rastgele yas degerini direk ogrenci dizisinin icine yazar. Dizi pointer gibi adres tuttugu icin & ile gondermedim.Ama gonderilebiliyor.
	printf("\nRastgele Olusan Ogrenciler\n\n");
	yazdir(ogrenci,kacKisi);	// Ogrenci dizisini yazar.
	
	onIkidenKucuklerOgrenciler=onIkidenKucukler(ogrenci,kacKisi);	// 12 Yasindan kucukler icin olusturulan liste degiskenine onIkidenKucukler fonksiyonundan donen degeri yazar.
	printf("\nYasi 12 den kucuk olan ogrenciler\n\n");
	yazdir(onIkidenKucuklerOgrenciler.yeniOnIkidenKucuk,onIkidenKucuklerOgrenciler.boyut);	// onIkidenKucuklerOgrenciler degiskenine fonksiyondan donen degeri esitlemistik. Fonksiyon bize hem 12 yasindan kucuklerin listesini hemde boyutunu dondurmustu. Simdi bu degerleri ekrana yazdiriyoruz.
		
	return 0;
}
