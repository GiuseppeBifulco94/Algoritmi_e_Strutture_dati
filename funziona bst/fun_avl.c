#include <stdio.h>
#include <stdlib.h>
#include "avl.h"
#include "fun_men.h"
#define MAX 1024


 
// Funzione che restituisce l'altezza dell'albero binario
int altezza(struct node* root){
    if(root == NULL) return -1;
    
    return (max_avl(altezza(root->left), altezza(root->right))+1);
}	

 
//Funzione che fra ijl confronto tra due varibili
int max_avl(float a, float b)
{
    return (a > b)? a : b;
}
 
/* Funzione che permette l'allocazione di un nuovo nodo. */
struct node* newNode_avl(float key)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->key   = key;
    node->left   = NULL;
    node->right  = NULL;
    node->height = 1;  // new node is initially added at leaf
    return(node);
}
 
//funzione che permette la rotazione a destra
struct node *rightRotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max_avl(altezza(y->left), altezza(y->right))+1;
    x->height = max_avl(altezza(x->left), altezza(x->right))+1;
 
    // Return new root
    return x;
}
 
////funzione che permette la rotazione a sinistra
struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;
 
    // Effettua rotazione
    y->left = x;
    x->right = T2;
 
    //  aggiornamento dell'altezza
    x->height = max_avl(altezza(x->left), altezza(x->right))+1;
    y->height = max_avl(altezza(y->left), altezza(y->right))+1;
 
    // Ritorna il nuovo nodo
    return y;
}
 
// Bilanciamento 
int getBalance(struct node *root)
{
    if (root == NULL)
        return 0;
    return altezza(root->left) - altezza(root->right);
}
 
//Funzione ricorsiva che permette inserimento e bilanciamento degli elementi nell'albero 
struct node* insert_avl(struct node* root, float key)
{
    /* 1.Esecuzione di un normale albero */
    if (root == NULL)
        return(newNode_avl(key));
 
    if (key < root->key)
        root->left  = insert_avl(root->left, key);
    else if (key > root->key)
        root->right = insert_avl(root->right, key);
    else // elementi uguali non sono permessi nell'albero
        return root;
 
    /* 2. aggiornamento dell'altezza per questo nodo */
    root->height = 1 + max_avl(altezza(root->left),altezza(root->right));
 
    /* 3. effettua il bilanciamento */
    int balance = getBalance(root);
 
    //se il nodo non e bilanciato va al 4. caso
 
    // rotazione sinistra sinistra
    if (balance > 1 && key < root->left->key)
        return rightRotate(root);
 
    // rotazione destra destra
    if (balance < -1 && key > root->right->key)
        return leftRotate(root);
 
    // rotazione sinistra destra
    if (balance > 1 && key > root->left->key)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }
 
    // rotazione destra sinistra
    if (balance < -1 && key < root->right->key)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    /* ritorna il nodo */
    return root;
}

//funzione per l'inserimento random degli elementi per la funzione insert_avl
struct node * random_avl(int index){
	int i = 0;
	struct node  *root = NULL;
	for(i=0; i < index; i++){
		root = insert_avl(root, rand() % MAX);
		}
	return root;
	}