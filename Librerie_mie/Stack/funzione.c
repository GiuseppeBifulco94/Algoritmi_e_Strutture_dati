/*funzioni per l'implementazione e creazione di uno stack*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "stack_code.h"




int *inizializzazione(){
	int *array =(int*)malloc(MAX_STACK *sizeof(int));
	array[0]=0;
	return array;
	}
	
int stack_vuoto(int *array){
	
	return array[0]==0;
	
	}

void push ( int *array, int val){
	
		
        array[0]=array[0]+1;
        array[array[0]]=val;
	
}

int pop(int *array){
		
		array[0]=array[0]-1;
		return array[array[0]+1];
   
}
	
int stack_pieno(int *array){
	return array[0]==MAX_STACK; 
    
	}

void rand_elem(int *array, int size){
	srand(time(NULL));
		
		for(int index =0; index < size; index++){
			push(array, rand() % 9);
			}
	
	}

int Stampa(int *array)
{
    int val;
    if(!stack_vuoto(array)){
		val=pop(array);
		printf("%d\t",val);
		Stampa(array);
		push(array,val);
		}
	printf("\n");
	return val;
}
