
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "fun_men.h"
#include "avl.h"

#define MAX 1024

int main(){
	srand(time(NULL));
	struct node * root=NULL;
	
	int rot;
	float ris=0;
	int n_abr;
	float key;
	int index;
	float media=0;
	int scelta,scelta2,scelta3;
	
 do{
	system("clear");
	printf("\n1)Gestione semplice di un albero binario di ricerca(Anche elementi uguali) .\n");
	printf("2)Altezza media di n alberi binari .\n");
	printf("3)Merge di 2 alberi binari.\n");
	printf("4)AVL di un albero binario di ricerca .\n");
	printf("5)Exit!.\n");
	printf("inserisci Scelta: ");
	scanf("%d",&scelta);
	system("clear");
	switch (scelta){
		case 1:
				
				do{
					system("clear");
					printf("\n--Gestione Albero--\n");
					printf("1)Inserimento elementi(anche uguali).\n");
					printf("2)Ricerca di un elemento.\n");
					printf("3)Eliminazione di un elemento.\n");
					printf("4)Stampa.\n");
					printf("5)Ritorna al menu precedente!\n");
					printf("Inserisci scelta:  ");
					scanf("%d",&scelta2);
					switch(scelta2){
						case 1:
							/*Inserimento random o singoli dell'albero con scelta*/
								printf("Inserire elementi randomici o singoli?\n");
								printf("1) Random.\t\t");
								printf("2) Singoli.\n");
								
								printf("Scelta: ");
								scanf("%d",&scelta3);
								if(scelta3==1){
									system("clear");
									printf("\nQuanti elementi casuali vuoi inserire?\n");
									scanf("%d",&index);
									root = random_x(index);
									
									}
								else{
									system("clear");
									printf("Inserisci elemento: ");
									scanf("%f",&key);
									root=insert(root,key);
									}
											
						break;
						
						case 2:
							/*Ricerca dell'elemento*/
								system("clear");
								struct node * nodo =NULL;
								printf("Inserisci elemento da cercare: ");
								scanf("%f",&key);
								nodo=search(root,key);
								if (nodo)
									printf("Elemento Trovato: %d",nodo->key);
								else 
									printf("Elemento non trovato\n");
								sleep(2);
						break;
						
						case 3:
								printf("\nQuanti elementi vuoi eliminare?\n");
								printf("1) Singolo.\t\t");
								printf("2) Tutti.\n");
								
								printf("Scelta: ");
								scanf("%d",&scelta3);
								if(scelta3==1){
								inorder(root);
								printf("Inserisci elemento da eliminare: ");
								scanf("%f",&key);
								root=deleteNode(root,key);
								}
								else{
									root=del_all(root);
									}		
						break;
						
						case 4:
								
								do{
									
									printf("\n--Gestione stampa--\n");
									printf("1)Stampa in ordine\n");
									printf("2)Stampa in postordine\n");
									printf("3)Stampa in preorder\n");
									printf("4)Ritorna al menu precedente!\n");
									printf("inserisci Scelta: ");
									scanf("%d",&scelta3);
									switch(scelta3){
										case 1:
													system("clear");
													printf("Stampa in ordine\n");
													inorder(root);
										break;
										
										case 2:
												system("clear");
												printf("Stampa in postordine\n");
												postorder(root);
												
										break;
										
										case 3:
												system("clear");
												printf("Stampa in preorder\n");
												preorder(root);
										break;
										
										default:
												printf("Scelta errata..\n");
										}
									}while(scelta3!=4);
						break;
						
						case 5:
							printf("Uscita");
						break;
						
						default:
						printf("Ripeti scelta..");
					}
					
					}while(scelta2!=5);
		break;
		
		case 2:	
		
		printf("--Altezza media di n alberi binari--\n");
		printf("Quanti alberi vuoi creare : ");
		scanf("%d",&n_abr);
		printf("elementi nell'albero ?");
		scanf("%d",&index);
		ris=0;
		media=ris;
		for(int i =0; i< n_abr;i++){
		root = random_x(index);
		media=media + altezza_1(root);
		root=del_all(root);
		}
		ris = ris + (media / n_abr);
		printf("La media delle altezze dell'albero è : %f",ris);
		free(root);		
		break;
		
		case 3:
		printf("--Merge tra 2 alberi binari--\n");
		break;
		
		case 4:
			printf("--Implementazione avl in un albero binario--\n");
			printf("Cosa si vuole fare?\n ");
			printf("1)Bilanciamento automatico       2)Numero di rotazioni\n");
			scanf("%d",&scelta);
				if(scelta==1){
					system("clear");
					printf("Quanti elementi vuoi inserire nel nell'albero binario(random)?\n");
					scanf("%d",&index);
					root = random_avl(index);
					preorder(root);}
				/*else {
					system("clear");
					printf("Quanti elementi vuoi inserire nel nell'albero binario(random)?\n");
					scanf("%d",&index);
					root = random_x(index);
					preorder(root);
					printf("\nScegliere numero di rotazioni e direzione!\n");
					printf("In quale direzione\n ");
					printf("1)Sinistra       2)Destra\n");
					scanf("%d",&scelta);
					if(scelta==1){
						printf("Quante rotazioni vuoi fare?\n");
						scanf("%d",&rot);
						for(int i=0;i<rot;i++){
							leftRotate(root->left);
							preorder(root);
							sleep(2);
							system("clear");
						}
					

					}else{
						printf("Quante rotazioni vuoi fare?\n");
						scanf("%d",&rot);
							for(int i=0;i<rot;i++){
							rightRotate(root);
						}
						preorder(root);
					}
					

				}*/
		break;
		
		case 5:
			printf("Arrivederci!");	
			root=del_all(root);
		break;
		
		default:	
				printf("Ripeti scelta..\n");
		}
	}while(scelta!=5);

	return 0;
	}