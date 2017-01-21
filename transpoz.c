// Transpoz Alma

#include <stdio.h>
#include <conio.h>

// Alan Ac
int alanAc(int **gelen,int x, int y){
	int i=0,j=0;

	gelen=(int **)malloc(y*sizeof(int *));
	
	for(i=0;i<y;i++){
		gelen[i]=(int *)malloc(x*sizeof(int));
	}
	
	return gelen;
}

// Matris Olustur
int matrisOlustur(int **gelen,int x,int y){
	int i=0,j=0;
	
	gelen=alanAc(gelen,x,y);	// Alan Ac
	
	// Icini Doldur
	for(i=0;i<y;i++){
		for(j=0;j<x;j++){
			scanf("%d",&gelen[i][j]);
		}
	}
	
	return gelen;	
}

// Transpoz Al
int transpozAl(int **gelen,int x, int y){
	int i,j;
	int **dondur;
	
	dondur=alanAc(dondur,y,x);	// Alan Ac
	
	// Transpoz Al
	for(i=0;i<x;i++){
		for(j=0;j<y;j++){
			dondur[i][j]=gelen[j][i];
		}
	}
	
	return dondur;
}



void yaz(int **gelen,int x,int y){
	int i,j;
	for(i=0;i<y;i++){
		for(j=0;j<x;j++){
			printf("%d",gelen[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int x=0,y=0;
	int **matrisDizim;
	
	
	// Dizi boyutu iste
	printf("Kaca kaclik bir dizi girmek istediginizi yaziniz:\n\n");
	scanf("%d",&x);
	printf("%d X ",x);
	scanf("%d",&y);
	printf("->boyutunda bir matris olusturulacak.\n");
	
	matrisDizim=matrisOlustur(matrisDizim,x,y);
	
	system("cls");
	yaz(matrisDizim,x,y);
	
	matrisDizim=transpozAl(matrisDizim,x,y);
	printf("\n#####\n\n");
	yaz(matrisDizim,y,x);

	
	return 0;
}
