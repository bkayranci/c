// Turkalp Burak KAYRANCIOGLU
// bkayranci

#include <stdio.h>
#include <string.h>
#include <conio.h>


enum haftaninGunleri{
	pazartesi=2,sali=4,carsamba=8,persembe=16,cuma=32,cumartesi=64,pazar=128
};

void okulAcikMi(int gelen){
	if((gelen&pazartesi)==pazartesi){
		printf("\nOkul Pazartesi gunu acik");
	}
	if((gelen&sali)==sali){
		printf("\nOkul Sali gunu acik");
	}
	if((gelen&carsamba)==carsamba){
		printf("\nOkul Carsamba gunu acik");
	}
	if((gelen&persembe)==persembe){
		printf("\nOkul Persembe gunu acik");
	}
	if((gelen&cuma)==cuma){
		printf("\nOkul Cuma gunu acik");
	}
	if((gelen&cumartesi)==cumartesi){
		printf("\nOkul Cumartesi gunu Kapali");
	}
	if((gelen&pazar)==pazar){
		printf("\nOkul Pazar gunu Kapali");
	}
}

int main(){
	enum haftaninGunleri gun;	
	
	okulAcikMi(carsamba|persembe);	// Carsamba ve Persembe Okul Acik Mi?
	
	return 0;
}
