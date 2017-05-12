
/*richiamo delle funzioni per la creazione dello stack*/

#ifndef gioco_h
#define gioco_h
#define MAX_STACK 100

struct TStack{
	int array[MAX_STACK+1];
};

typedef struct TStack* Stack;

Stack inizializzazione();
int stack_vuoto(Stack);
void push( Stack, int val);
int pop(Stack);
int stack_pieno(Stack);
void rand_elem(Stack, int size);
int Stampa(Stack);
int gioco(Stack , Stack );
#endif
