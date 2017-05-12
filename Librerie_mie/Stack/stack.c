/*Implementazione per la creazione dello stack con un semplice main che esegue sia il push che il pop dallo stack*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack_code.h"




int main(){
	
int *array;

int size, val; /* variabile size per la grandezza dello stack, variabile val per il valore da inserire(push)*/
int scelta;

printf("\nQuanti elementi vuoi inserire nello stack ( massimo %d elementi): ", MAX_STACK);
scanf("%d", &size);

while ( size >  MAX_STACK){
		system("clear");
		printf("\n Max %d elementi superato!",MAX_STACK);
		scanf("%d",&size);
		}
		array=inizializzazione();
		
		rand_elem(array,size);
		
		Stampa(array);
		
		printf("1: Inserisci un elemento nello stack(push).\n");
		printf("2: Estrai un elemento dallo stack(pop).\n");
while(scelta >=1 || scelta<=3){		
	printf("Scelta: ");
	scanf("%d", &scelta);
	
		switch(scelta){
			case 1:
				if(!stack_pieno(array)){
					printf("inserisci val: ");
					scanf("%d",&val);
					push ( array, val);
					Stampa(array);
				}
				else{
					printf("stack pieno\n");}
					break;
			
			case 2:
				if(!stack_vuoto(array)){
					pop(array);
					Stampa(array);
				}
				else
					printf("stack vuoto\n");
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


