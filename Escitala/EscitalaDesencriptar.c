#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char text[200];
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
	FILE *fp;
	fp = fopen("texto","r");
	int columnas, filas1;
	int i=0, j ,k = 0;
	srand(time(NULL));
	do{
		fscanf(fp,"%c",&text[i]);
		i+=1;
	}while(!feof(fp));

	printf("Numero de columnas :");
	scanf("%d",&columnas);	
	filas1=(int)filas(columnas);
	
	char matriz[columnas][filas1];
	for(i=0 ; i<columnas; i++)
		for(j=0 ; j<filas1; j++,k++){
			matriz[i][j] = text[k];	
			if(k >= lon)
				matriz[i][j] = ' ';
		}
	
	int orden[filas1];

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
	for(i=0; i<filas1 ; i++){
		for(j=0; j<columnas ;j++){
			printf("%c",matriz[orden[j]][i]);
		}
	}
	printf("\n");
}


