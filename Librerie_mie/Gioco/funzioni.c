#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gioco.h"



//Funzione per lo svolgimento del gioco e controllo del vinzitore	
int gioco( Stack S1, Stack S2){
	int elem1, elem2;//conterrà gli elementi per il controllo del vincitore
	int vincitore = 0;//variabile per dire chi e stato il vincitore
	
	
	
	
	//controlla se i due stack non sono vuoti
	if(!stack_vuoto(S1) && !stack_vuoto(S2)){
		elem1= pop(S1);//copia il valore in testa in elem
		elem2= pop(S2);

		if((elem1+elem2)%10 < 5){
			push(S1,elem1);
			}
		else{
			push(S2,elem2);
			}
		
		vincitore = gioco(S1,S2);
		
		if(vincitore == 1 && (elem1+elem2)%10 >= 5) 
			push(S1,elem1);
		else if (vincitore == 1 && (elem1+elem2)%10 < 5) 
			push(S2,elem2);
		}
		
	if(stack_vuoto(S1))//nel caso in cui lo stack n.1 e vuoto
		return 2;//vince il n.2
	else if (stack_vuoto(S2))//nel caso in cui lo stack n.2 e vuoto
		return 1;//vince il n.1
	
		
	return vincitore;
	}


Stack inizializzazione(){
	Stack S=malloc(sizeof(struct TStack));
	S->array[0]=0;
	return S;
	}
	
int stack_vuoto(Stack S){
	
	return S->array[0]==0;
	
	}

void push ( Stack S, int val){
	   S->array[0]=S->array[0]+1;
        S->array[S->array[0]]=val;
	
}

int pop(Stack S){
		
		S->array[0]=S->array[0]-1;
		return S->array[S->array[0]+1];
   
}
	
int stack_pieno(Stack S){
	return S->array[0]==MAX_STACK; 
    
	}



int Stampa(Stack S)
{
    int val;
    if(!stack_vuoto(S)){
		val=pop(S);
		printf("%d\t",val);
		Stampa(S);
		push(S,val);
		}
	
	return val;
}
