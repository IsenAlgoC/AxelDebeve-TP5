#include <stdlib.h>
#include <stdio.h>
#include "tab.h"
#define TAILLEINITIALE 10

int main() {
	TABLEAU tab = newArray();
	printf("Le nombre d'elements dans le tableau est %d", tab.eltsCount); // Affichage du nombre d'éléments (valeurs non nulles dans le tableau)
	printf("\nLa taille du tableau est : %d", tab.size); // Affichage taille tableau
	displayElements(&tab, 1, 10); // Affichage tableau initial

	setElement(&tab, 1, 4);
	setElement(&tab, 3, 5);
	setElement(&tab, 12, 3); // Initialement, le tableau est de taille 10. Il est donc agrandi pour placer 3 en position 12 grâce à la fonction "incrementArraySize" dans la fonction "setElement".
	//printf("\n On insère 4 à la position 1, puis 5 à la position 3 puis 3 à la position 12");
	printf("\nIl y a %d elements dans le tableau", tab.eltsCount);
	printf("\nLa taille du tableau est de %d", tab.size);
	displayElements(&tab, 1, tab.size); // Affichage du tableau avec les 3 valeurs ajoutées

	setElement(&tab, 2, 2);
	setElement(&tab, 5, 8);
	setElement(&tab, 15, 12);
	setElement(&tab, 18, 20);
	setElement(&tab, 24, 24);

	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount); // Affichage du nombre d'éléments dans le tableau, comprenant les 5 valeurs ajoutées, + les 3 précédentes
	printf("\nLa taille du tableau est de %d", tab.size); // Affichage de la taille du tableau qui est désormais de 24, puisqu'un élément se trouve en position 24.

	displayElements(&tab, 1, tab.size); // Affichage du tableau avec les 5 éléments ajoutés

	deleteElements(&tab, 2, 12);   // Suppression des éléments entre la 2ème et la 12ème valeur
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nLa taille du tableau est désormais de %d", tab.size); // Affichage de la nouvelle taille du tableau après la suppression des éléments.
	displayElements(&tab, 1, tab.size); // Affichage du tableau après la suppression des éléments
	setElement(&tab, 18, 5);
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nLa taille du tableau est de %d", tab.size);
	displayElements(&tab, 1, tab.size);
	deleteElements(&tab, 7, 4); // Suppression des éléments entre la 4ème et la 7ème valeur
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nLa taille du tableau est de %d", tab.size);
	displayElements(&tab, 1, tab.size); // Affichage du tableau
	printf("\nVoici l'affichage du tableau entre la position 9 et 14 :");
	displayElements(&tab, 9, 14); // Affichage du tableau entre la position 9 et 14
}