// 13.12.2016
//Duzgun Calismamaktadir.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.141592653589793

typedef struct noktaYapisi{
	int x;
	int y;
}noktaYapisi;

noktaYapisi dondurFonksiyon(int a,int b,double teta){
	noktaYapisi d;
	double r=((double)teta*PI)/180.0;
	d.x=(cos(r)*a)-(sin(r)*b);
	d.y=(sin(r)*a)+(cos(r)*b);
	printf("Yeni nokta: (%d,%d)\n",d.x,d.y);
	return d;
}

int main(){
	noktaYapisi nokta1;
	noktaYapisi yNokta1;
	
	int aci=90;
	nokta1.x=5;
	nokta1.y=5;
	
	yNokta1=dondurFonksiyon(nokta1.x,nokta1.y,aci);
	
	printf("Yeni Nokta: (%d,%d)\n",yNokta1.x,yNokta1.y);
	
	return 0;
}
