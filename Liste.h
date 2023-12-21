#include<stdio.h>
#include<stdlib.h>
#ifndef _LISTE
#define _LISTE



struct sCellule
{
  int info;
  struct sCellule *suivant;
  struct sCellule *precedent;
};
typedef struct sCellule Cellule;


struct sListe
{
  Cellule *prem;
  Cellule *last;
};
typedef struct sListe Liste;


void initialise(Liste * l) {
    l->prem = NULL;
    l->last = NULL;
	/*intialise the linked list with NULL*/ 
}

int estVide(const Liste * l){// for test if the linked list is vide or not
	if(l->prem == NULL) /*if the l->prem is vide that mean also the 
	                    linked list cellule is vide*/
	return 1 ;
	else // not vide 
	return 0 ;
}


unsigned int nbElements(const Liste * l){
	  unsigned int count = 0; // it's a counter the first node is 1.
    Cellule *current = l->prem; // create a copy of the linked list
    while (current != NULL) { /* loop untill the current is NULL (the last node ) beacause every 
	time current take the next of nodes */
        count++;
        current = current->suivant;
    }
    return count;
}

void affichageListeGaucheDroite(const Liste * l){
	 Cellule *current = l->prem; //Create a copy of the linked list l
    
    while (current != NULL) { /* we use this conditon because every time 
	current take suivant untill the end of the linked list (suivant == NULL)*/
        printf("%d\t ", current->info); //print the data from begin to the end
        current = current->suivant; // to print the data of the next node
    }
    printf("\n");
}


void affichageListeDroiteGauche(const Liste * l){
	    Cellule *current = l->last; /*Create a copy of the linked list l but the current take
	    the last node*/
    
    while (current != NULL) {/* we use this conditon because every time 
	current take precedent untill the begin of the linked list (precedent == NULL)*/
        printf("%d\t ", current->info);//print the data of the nodes
        current = current->precedent; // to print the data of the previous node
    }
    printf("\n");
}

void ajoutEnTete(int e,Liste * l){
	Cellule *newnode = (Cellule *)malloc(sizeof(Cellule));//Create a now Node
    newnode->info = e;	// charge the node with data
    newnode->suivant = l->prem; // the next of the new node take  adress of the the first node
    newnode->precedent = NULL; // the previous will be NULL because it's first node
    // the new Node that created now it's the head of the list

    if (l->prem != NULL) {
        l->prem->precedent = newnode;
    } else {
        l->last = newnode;
    }

    l->prem = newnode;
}

void ajoutEnQueue(int e, Liste * l){
	Cellule *newnode = (Cellule *)malloc(sizeof(Cellule));//Create a now Node
    newnode->info = e;// charge the node with data
    newnode->suivant = NULL;// the last will be NULL because it's last node
    newnode->precedent = l->last;// the previous of the new node take  adress of the the last node
    // the new Node that created now it's the queue of the list
    
    if (l->last != NULL) {
        l->last->suivant = newnode;
    } else {
        l->prem = newnode;
    }

    l->last = newnode;
}

void suppressionEnTete(Liste * l){

  if (l->prem != NULL) {// check if the linked list is not empty
        Cellule *temp = l->prem; // creat copy of pointer of the first node
        l->prem = l->prem->suivant;// move the head pointer to the next node in the linked list


        if (l->prem != NULL) {// check if there is still a node after removing the head
            l->prem->precedent = NULL;// set the previous pointer of the new head to NULL
        } else {
            l->last = NULL;// if the list was empty, set the last pointer to NULL
        }

        free(temp);// deallocate the memory that allocated by the removed node
    }
}

void videListe(Liste * l){
	 Cellule *current = l->prem;// save the adresse of the next node
    Cellule *next;// creat temporary pointer

    while (current != NULL) {// parcours the linked list until the last node
        next = current->suivant;//parcours
        free(current);// deallocate the memory that allocated by the removed node
        current = next;// move to the next node
    }
    //the list is empty now
    l->prem = NULL;// set the head pointer to NULL
    l->last = NULL;// set the last pointer to NULL
}



void affectation(Liste * l1, const Liste * l2){
 // clear the  list l1
 videListe(l1);
    Cellule *current = l2->prem;

    while (current != NULL) {// parcours the linked list until the last node
        ajoutEnQueue(current->info, l1);//add element with the data of the list 2
		        current = current->suivant;//parcours
    }
}

int rechercheElement(int e, const Liste *l){
	  int position = 0; // it's a counter
    Cellule *current = l->prem; //we create a copy of the linked list

    while (current != NULL) { // untill current is NULL(run untill the last node)
        if (current->info == e) {// if the found the element exit from loop end return number of position
            return position;
        }
        position++;
        current = current->suivant;
    }
    return -1; // we return -1 in the main we use condition if -1 element not found or else
}


void insererElement(int e, Liste * l, int position){
	if (position > nbElements(l)) { /* Invalid position, do nothing, we call fonction nbElements to 
	count the number of nodes and +1 because the number of node in function start from 0 */
        return;
    }

    if (position == 0) { 
        ajoutEnTete(e, l);/* position is  that mean add in the first and 
		we have function to add a node in the first linked list*/
    } else if (position == nbElements(l)) { /*endif the position equal the number 
	of nodes that mean add the node in the end of linked list*/
        ajoutEnQueue(e, l);/*end we have funtion that add a node in the end 
		of linked list and we call it*/
    } else {/* position is totally less than number of node and completely bigger than 1*/
        Cellule *current = l->prem; // create a copy of linked list
		int i;
        for (i = 0; i < position; i++) { // counter from 0 to position
            current = current->suivant; // to run (parkour)from first node to position node
        }

        Cellule *newnode = (Cellule *)malloc(sizeof(Cellule)); //Create a new node 
        newnode->info = e; // add the data in the newnode
        newnode->suivant = current; // the next of the new node take adress of current
        newnode->precedent = current->precedent; // precedent  of the new node take the precedent of the cuurent node
        current->precedent->suivant = newnode; /* and the next of the node li 9bal node that created take the adress 
		of the newnode*/
        current->precedent = newnode; /*and current precedent take the adress of new node bach n9dro nrj3o liha*/
    }
}




#endif