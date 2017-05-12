#ifndef FUN_MEN_h
#define FUN_MEN_h

#define MAX 1024

struct node
{
    int key;
    struct node *left, *right;
    int height;
};

//fra il confronto tra 2 float per vedere qual'e il maggiore
int max(float a, float b);

//prototipo della funzione per il calcolo dell'altezza dell'albero
int altezza_1(struct node* root);

//prototipodella funzione per la creazione di un nuovo nodo
struct node *newNode(float item);

//prototipo della funzione dper l'inserimento random degli elementi nell'albero
struct node * random_x(int index);

//stampa in ordine
void inorder(struct node *root);

//stampa in postordine
void postorder(struct node *root);

//stampa in preordine
void preorder(struct node *root);

//prototipo della funzione per l'inserimento di elementi nell'albero
struct node* insert(struct node* root, float key);

//prototipo della funzione usato per la cancellazione di un nodo nell'albero
struct node * minValueNode(struct node* node);

//prototipo della funzione per la cancellazione di un nodo
struct node* deleteNode(struct node* root, float key);

//prototipo per la ricerca di un elemento nell'albero
struct node * search(struct node*root, float key);

//elimina tutto l'albero creato
struct node *del_all(struct node* root);

#endif
