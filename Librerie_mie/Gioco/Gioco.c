#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gioco.h"



int main(){
	srand(time(NULL));
	
	int size;
	int index;
	printf("Inserisci la grandezza degli stack:  ");
	scanf("%d",&size);
	
	Stack S1=inizializzazione();//inizializzazione del primo stack
	Stack S2=inizializzazione();//inizializzazione del secondo stack
	
	//for che permette l'inserimento casuale degli elementi nei due stack
	for(index=0; index < size;index++){
		push(S1, 1 + rand() % 9);
		push(S2, 1+ rand() % 9);
		}
		
	printf("\nPila 1: ");
	Stampa(S1);
	printf("\nPila 2: ");
	Stampa(S2);
	
	system("clear");
	
	if(gioco(S1,S2) == 1){
		printf("\nLo stack numero 1 vince:\n");
		Stampa(S1);
	}else {
		printf("\nLo stack numero 2 vince:\n");
		Stampa(S2);
		}
	
	printf("\nARRIVEDERCI");
	return 0;
	}

