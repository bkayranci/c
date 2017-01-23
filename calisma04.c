// Turkalp Burak KAYRANCIOGLU
// bkayranci

#include <stdio.h>
#include <string.h>
#include <conio.h>


typedef struct kayitYapisi{
	int no;
	int deger;
	struct kayitYapisi *sonraki,*onceki;
}kayitYapisi;

kayitYapisi *ilk,*son,*gecici;

void ekle(){
	printf("No ve Deger Girin : \n");
	
	if(ilk==NULL){	//ilk kayitsa
		ilk = (kayitYapisi *) malloc(sizeof(kayitYapisi));
		scanf("%d",&ilk->no);
		scanf("%d",&ilk->deger);
		ilk->sonraki = NULL;
		ilk->onceki = NULL;	//ikinci bag.
		son = ilk;
	}
	
	else if(son == ilk){	//ikinci kayitsa
		son = (kayitYapisi *) malloc(sizeof(kayitYapisi));
		scanf("%d",&son->no);
		scanf("%d",&son->deger);
		ilk->sonraki = son;
		son->sonraki = NULL;
		son->onceki = ilk;	//ikinci bag.
	}
	
	else{	//ikiden fazla kayit varsa
		gecici = (kayitYapisi *) malloc(sizeof(kayitYapisi));
		scanf("%d",&gecici->no);
		scanf("%d",&gecici->deger);
		son->sonraki = gecici;
		gecici->onceki = son;	//bu iki satirda gecici sona eklendi.
		
		////////////////
		son = gecici;
		son->sonraki = NULL; //bu iki satirda da son isaretcisi son gelen veriye aktarildi.
	}
}

void listele(){
	gecici = ilk;
	
	printf("\n--Birinci Gosterim--\n\n");
	
	while(gecici != NULL){
	
		printf("\tNo:%d\n", gecici->no);
		printf("\tDeger:%d\n", gecici->deger);
		gecici = gecici->sonraki;
	}
	
	gecici = son;
	
	printf("\n--Ikinci Gosterim--\n\n");
	
	while(gecici != NULL){
	
		printf("\tNo:%d\n", gecici->no);
		printf("\tDeger:%d\n", gecici->deger);
		gecici = gecici->onceki;
	}
}

int main(){
	ekle();
	ekle();
	listele();
	
	return 0;
}
