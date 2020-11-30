#include <stdlib.h>
#include <stdio.h>
#include "tab.h"
#define TAILLEINITIALE 10

TABLEAU newArray() {
	TABLEAU tab;
	tab.elt = (int*)malloc(sizeof(int) * TAILLEINITIALE);  // On allloue une taille de TAILLEINITIALE * taille d'un entier en m�moire
	if (tab.elt != NULL) { // Si malloc a fonctionn�, initialisation du tableau avec des 0
		for (int i = 0; i < TAILLEINITIALE; i++) {
			*(tab.elt + i) = 0;
		}
	}
	tab.size = TAILLEINITIALE;
	tab.eltsCount = 0;
	return(tab);
}

int incrementArraySize(TABLEAU* tab, int incrementValue) {
	if ((incrementValue < 0) || ((*tab).elt == NULL)) {
		return(-1);
	}
	else {
		int* tmp = tab->elt; // Sauvegarde du pointeur
		tab->elt = (int*)realloc((*tab).elt, sizeof(int) * (tab->size + incrementValue));
		if (tab->elt == NULL) { // Echec de la r�allocation
			tab->elt = tmp;    // Restitution du pointeur pr�c�dent
			return(-1);         // Cela permet d'�viter que la valeur de tab soit modifi�e si le realloc ne fonctionne pas 
		}
		else {
			tab->size += incrementValue;
		}
	}
	return(tab->size);
}

int setElement(TABLEAU* tab, int pos, int element) {
	printf("\nOn insere %d a la position %d", element, pos);
	int ancienneTaille = tab->size;
	if (pos <= tab->size) {
		//printf("\n L' est dans le tableau");
		if (*(tab->elt + pos - 1) == 0) {
			tab->eltsCount++;
		}
		*(tab->elt + pos - 1) = element;
		return(pos);
	}
	else {
		//	printf("\ntableau agrandi");
		if (incrementArraySize(tab, pos - tab->size) == -1) { // Agrandissement du tableau. Si �chec, retour � 0.
			return(0);
		}
		for (int i = 0; i < pos - ancienneTaille; i++) {  // Remplissage des nouvelles cases par des 0.
			*(tab->elt + ancienneTaille + i) = 0;
		}
		*(tab->elt + pos - 1) = element; // Agrandissement r�ussi, insertion du nouvel element et augmentation du nombre d'�l�ments
		tab->eltsCount++;                // Taille mise � jour dans la fonction "incrementArraySize"
		return(pos);
	}
}

int displayElements(TABLEAU* tab, int startPos, int endPos) {
	printf("\nVoici le tableau :\n");
	if (((startPos < 1) || (endPos < 1)) || (startPos > tab->size) || (endPos > tab->size) || (tab == NULL)) { // Erreur si position plus petite que 1 ou en dehors de la taille du tableau
		return(-1);
	}
	else {
		if (startPos > endPos) { // Si l'utilisateur entre une valeur de d�part sup�rieure � la valeur d'arriv�e alors on inverse les deux pour ne pas renvoyer d'erreur
			int tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		for (int i = startPos - 1; i < endPos; i++) {  // Affichage des �l�ments du tableau de startPos-1 � endPos
			printf("%d ", *(tab->elt + i));
		}
		printf("\n");
		return(0);
	}
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) {
	if (((startPos < 0) || (endPos < 0)) || (startPos > tab->size) || (endPos > tab->size)) { // Erreur si position n�gative ou en dehors de la taille du tableau
		return(-1);
	}
	else {
		if (startPos > endPos) { // Si  l'utilisateur a entr� une valeur de d�part sup�rieur � la valeur d'arriv�e, inversion des deux pour ne pas renvoyer d'erreur
			int tmp = startPos;
			startPos = endPos;
			endPos = tmp;
		}
		printf("On supprime les elements du tableau entre la position %d et la position %d", startPos, endPos);
		int nbElementsSuppr = endPos - startPos + 1; // Calcul du nombre d'�l�ments � supprimer
		for (int i = 0; i < nbElementsSuppr; i++) {
			if (*(tab->elt + startPos - 1 + i) != 0) { // Si on supprime un �l�ment diff�rent de 0
				tab->eltsCount--;                      // Suppression d'un �lement du tableau donc d�cr�mentation de tab.eltsCount
			}
		}
		for (int i = 0; i < tab->size - endPos; i++) {
			// printf(" On supprime %d", *(tab->elt + startPos - 1 + i));
			*(tab->elt + startPos - 1 + i) = *(tab->elt + startPos - 1 + nbElementsSuppr + i); // D�calage de nbElementsSuppr vers la gauche
		}
		int* tmp = tab->elt; // Sauvegarde du pointeur actuel
		tab->elt = (int*)realloc((*tab).elt, sizeof(int) * (tab->size - nbElementsSuppr));
		if (tab->elt == NULL) { // Echec de la r�allocation
			tab->elt = tmp;     // Restitution du pointeur pr�c�dent
			return(-1);         // Cela permet d'�viter que la valeur de tab soit modifi�e si le realloc ne fonctionne pas 
		}
		else {
			tab->size = tab->size - nbElementsSuppr;  // Mise � jour de la taille
		}
		return(tab->size);
	}
}