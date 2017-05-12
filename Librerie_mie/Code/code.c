#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "code.h"

int main(){
	int size;
	int scelta;
	int val;
	
	printf("\nQuanti elementi vuoi insierire? (massimo %d elementi\n",MAX_EL);
	scanf("%d: ",&size);

	coda C = coda_inizial();
	coda_random(C,size);
	stampa_bis(C);
	
	system("clear");
	
	
while(scelta >=1 || scelta<=3){	
		
	printf("\nScelta: \n");
	scanf("%d", &scelta);
	
		switch(scelta){
			case 1:
				system("clear");
				if(!coda_piena(C)){
					printf("Elemento da inserire: \n");
					scanf("%d",&val);
					coda_insert(C, val);
					stampa_bis(C);
				}else{
					printf("La coda è piena.\n");
					
				}
			break;	
			case 2:	
				if(!coda_vuota(C)){
					elimina_elem(C);
					stampa_bis(C);
				}else{
					printf("La coda è vuota.\n");
					}
			break;
			
			case 3:
			printf("Arrivederci");
			return 0;
			break;
		
		default: 
				printf("Errore: ripeto!");
}	
}
	
	
	return 0;
	}

