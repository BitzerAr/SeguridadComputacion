#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char te[40];
void ingresar(){	
	printf("\n\nINGRESE EL NOMBRE DEL ARCHIVO O COPIE EL TEXTO EN <encriptado> \n\n ");
	printf("<<EL DESPLAZAMIENTO ES EL MOVIMIENTO QUE HARA CADA LETRA PARA PODER DESENCRIPTAR EL ARCHIVO,\n DE ACUERDO AL CODIGO ASCII EN SU REPRESENTACION DECIMAL\n\tEjemplo para el ejemplo 5 : \n\t\tDesplazamiento=-3 \n\t\t Encriptado : F<>70 \n\t\t Desencriptado : F-3<>67=C\n\t\t Entonces : F<>C\n\n");
	printf("Ingresar Archivo : ");
	scanf("%[^\n]",te);
}

int main(){
	ingresar();
	FILE *fp;
	fp = fopen(te,"r");
	char *texto;
	char c,bandera=' ';
	int i=0,a,desplazo;
	printf("\n<<Trabaje con el ejemplo 5\nMi desplazamiento es de -3>>\n");	
	printf("\nIngresar el desplazamiento para desencriptar : ");
	scanf("%d",&desplazo);
	printf("\n");
	do{
		fscanf(fp,"%c",&texto[i]);
		if(!feof(fp)){
			if( texto[i]==' ' || texto[i]==',' || texto[i]==';' || texto[i]=='.' || texto[i]=='"')
				c=texto[i];
			else{
				a=texto[i];
				if(a>96 && a<122)
					a=a-32;
				if(a+desplazo<65 )
					c=texto[i]+26+desplazo;
				else if( a+desplazo>90 )
					c=texto[i]-26+desplazo;
				else
					c=texto[i]+desplazo;
			}
		}
		if( c=='N' || c=='n'){
			bandera=c;
			i++;	
			continue;				
		}
		if((bandera=='n'||bandera=='N' )&& (c=='h' || c=='H')){
			printf("Ñ");
			bandera=' ';
			i++;
			continue;
		}
		if(bandera==' '){
			printf("%c",c);
		}
		else{
			printf("%c%c",bandera,c);
			bandera=' ';
		}
		i++;
	}while(!feof(fp));
	fclose(fp);
}
