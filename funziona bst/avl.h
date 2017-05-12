#ifndef AVL_h
#define AVL_h

#include "fun_men.h"
#define MAX 1024
// funzione che restituisce l'intero tra 2 variabili
int max_avl(float a, float b);
 
// funzione che restituisce l'altezza di un albero
int altezza(struct node* root);

/* funzione per la creazione di un nuovo nodo e figlio destro e sinistro. */
struct node * newNode_avl(float key);

//funzione rotazione a destra
struct node *rightRotate(struct node *y);

//rotazione a sinistra
struct node *leftRotate(struct node *x);
 
// Get Balance factor of node N
int getBalance(struct node *root);
 
//Funzione ricorsiva che permette inserimento e bilanciamento degli elementi nell'albero 
struct node* insert_avl(struct node* root, float key);

//funzione per l'inserimento random degli elementi per la funzione insert_avl
struct node * random_avl(int index);

#endif
