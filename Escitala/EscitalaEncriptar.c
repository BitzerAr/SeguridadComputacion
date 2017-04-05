#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char text[200];
void ingresar(){	
	printf("INGRESAR TEXTO : ");		
	scanf("%[^\n]",text);
}
int lon;
float filas(int columnas){	
	float filas1;
	int bandera;
	lon= strlen(text);
	filas1 =  lon/(columnas*1.0);
	bandera = (int) filas1;
	if( filas1/bandera == 1)
		return filas1;
	else
		return filas1+1;
}
int main(){
	int columnas, filas1;
	int i, j, k=0;
	FILE *fp;
	srand(time(NULL));

	fp=fopen("texto","w");
	ingresar();

	printf("Numero de columnas :");
	scanf("%d",&columnas);
	filas1=(int)filas(columnas);
	
	char matriz[filas1][columnas];
	
	for(i = 0 ; i < filas1; i++)
		for(j = 0 ; j < columnas; j++, k++){
			matriz[i][j] = text[k];	
			if(k >= lon)
				matriz[i][j] = ' ';
		}
		
	int orden[columnas];
	for( i=0; i<columnas ;i++){
		orden[i]=i;
		/*rand()%columnas;
		for(j=0; j<i;j++){
			if(orden[j] == orden[i]){ 
				i--;
				break;
			}
		}*/
	}
	for(i=0; i<columnas ; i++){
		for(j=0; j<filas1 ;j++){
			printf("%c",matriz[j][orden[i]]);
			fprintf(fp,"%c",matriz[j][orden[i]]);
		}
	}
	printf("\n");
}


