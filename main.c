#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Liste.h"


int main(){
	
	int i, alea;
	Liste lili, lala;

	srand(time(NULL));
	
	initialise(&lili); // initialise lili with NULL
	
	for (i = 0; i < 5; i++) { /* Create a nodes and charge it with random data, and add them in the end of the linked list
		with function ajoutEnQueue*/
        alea = rand() % 100;
		ajoutEnQueue(alea, &lili);
		//Remplissage de lili : test de ajoutEnTete et AjoutEnQueue
    }
    
    printf("affichage liste gauche droite:\n");
	affichageListeGaucheDroite(&lili); // print linked list from the left to right
  	
	printf("affichage liste droite gauche:\n");
	affichageListeDroiteGauche(&lili); // print linked list from right to left
	
	affectation(&lala, &lili);/* Creation d'une copie de lili */
	
	printf("insertion en tete: \n");
	ajoutEnTete(208, &lili); // add a node in begin of linked list
	
	affichageListeGaucheDroite(&lili); // test de ajoutEnTete
	
	printf("insertion en queue:\n");
	ajoutEnQueue(207, &lili); // add a node in the end of linked list
	
    affichageListeGaucheDroite(&lili); //test de AjoutEnQueue
	int pos ;
	int n ;
	printf("\nentrer la nombre pour inserstion:\t");
	scanf("%d",&n); // user enter data
	printf("entrer la position:\t");
	scanf("%d",&pos);// user enter position for insertion
	insererElement(n, &lili, pos);
	affichageListeGaucheDroite(&lili);//test of insererElement
	
	printf("\nentrer un element pour recherch:\t");
	scanf("%d",&n);
	int position=rechercheElement(n, &lili);/* because the function return -1 if element not found or 
	return return number of position*/
	 if (position != -1) { 
        printf("Element %d found at position %d in LiLi.\n", n, position);
    } else {
        printf("Element %d not found in LiLi.\n", n);
    }
    
    videListe(&lili);
    videListe(&lala);

   return 0;
}