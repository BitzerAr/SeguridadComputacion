#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char *text="N..NAEEA.ENEH.GR.SAOTQ.C....N.RBS.T.IQIAEI.BRUEEAUIP...LUBNRE.OTDAES.TUI..BISU.T.SACAREC.YEOUDSQD.YOAOSAUEUA.N.MRIEN.BEAOMEQOSAAB.HTRES.TYANOUTRSTESED.SOBO.IP...";
void ingresar(){	
	printf("Ingresar texto :\n %s\n",text);	
	
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
	srand(time(NULL));
	int columnas, filas1;
	ingresar();
	printf("Ingresar numero de columnas :");
	scanf("%d",&columnas);
	
	filas1=(int)filas(columnas);
	int i, j, k=0;
	char matriz[columnas][filas1];
	for(i=0 ; i<columnas; i++){
		for(j=0 ; j<filas1; j++,k++){
			matriz[i][j] = text[k];	
			if(k >= lon)
				matriz[i][j] = ' ';
		}
	}
	
	int orden[columnas];

		orden[6]=0;
		orden[0]=1;
		orden[2]=2;
		orden[4]=3;
		orden[1]=4;
		orden[3]=5;
		orden[5]=6;

	for(i=0; i<filas1 ; i++){
		for(j=0; j<columnas ;j++){
			printf("%c",matriz[orden[j]][i]);
		}
	}
	printf("\n");
}
