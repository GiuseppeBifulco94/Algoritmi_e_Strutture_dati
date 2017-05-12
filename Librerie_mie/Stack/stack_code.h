/*richiamo delle funzioni per la creazione dello stack*/

#ifndef Library_stack_h
#define Library_stack_h


#define MAX_STACK 100

int *inizializzazione();
int stack_vuoto(int *array);
void push( int *array, int val);
int pop(int *array);
int stack_pieno(int *array);
void rand_elem(int *array, int size);
int Stampa(int *array);

#endif
