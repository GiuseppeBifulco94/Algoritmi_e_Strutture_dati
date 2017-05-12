
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fun_men.h"
#define MAX 1024


	
// funzione per la creazione di un nuovo nodo nell'albero

struct node *newNode(float item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;
   
    return temp;
}
 
// funzione per la stampa in ordine
void inorder(struct node *root)
{
    if (root != NULL)
    {	
        inorder(root->left);
        printf("%d ->", root->key);
        inorder(root->right);
        
    }
}

//fuzione per la stampa in postordine
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ->", root->key);
    }
}

//funzione per la stampa in preordine
void preorder(struct node *root)
{
    if (root != NULL)
    {
		printf("%d ->", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
 
//funzione per l'inserimento di un nuovo nodo nell'albero
struct node* insert(struct node* root, float key)
{
    //se l'albero e vuoto torna a newnodo 
    if (root != NULL){ 
        if (key <= root->key)
             root->left  = insert(root->left, key);
        else if(key>=root->key)
             root->right = insert(root->right, key);
              else {
                  if(root->left == NULL)
                        root->left= newNode(key);
                  else if(root->right == NULL)
                        root->right= newNode(key);
                  else
                        root = insert(root->left,key);
              }
            
}else root=newNode(key);  
    
    return root;
}


struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

struct node *del_all(struct node* root){
	 if(root!=NULL){
			del_all(root->left);
			del_all(root->right);
			free(root);
	}
	return NULL;
	 }
 
/* data una chiave questa viene eliminata dall'albero e ritorna il nuovo nodo */
struct node* deleteNode(struct node* root, float key)
{
    // caso base
    if (root == NULL) return root;
 
    // se la chiave e minore del nodo si procede nel sotto albero sinistro
    if (key < root->key)
        root->left = deleteNode(root->left, key);
 // se la chiave e minore del nodo si procede nel sotto albero destro
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

struct node * search(struct node*root, float key){
	if(root!=NULL ) {
		if(root->key < key){
			return search(root->right,key);
		}else if(root->key>key){
			return search(root->left,key);
		} else {
			return root;
		}
	} 
return root;
}

struct node * random_x(int index){
	int i = 0;
	struct node  *root = NULL;
	for(i=0; i < index; i++){
		root = insert(root, rand() % MAX);
		}
	return root;
	}
	
int max(float a, float b){
	return (a>b)? a:b;
	}

int altezza_1(struct node* root){
    if(root == NULL) return -1;
    
    return (max(altezza_1(root->left), altezza_1(root->right))+1);
}	

