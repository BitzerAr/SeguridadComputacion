#include<stdio.h>
int main (){
	unsigned a = 0xf05a;
	int b = a;
	char c[6]="MIGUEL";
	char d[6]="UNIUNI";
	char p;
	int i;
	for(i=0 ; i<6 ; i++)
		printf("%i",c[i]^d[i]);
	printf("\n");
	//printf("%x %x\n",c,d);
	/*printf ("%x\n" ,a>>6);
	printf ("%x\n" ,b>>6);*/
}
