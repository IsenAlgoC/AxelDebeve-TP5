#include <stdlib.h>
#include <stdio.h>
#include "tab.h"
#define TAILLEINITIALE 10

int main() {
	TABLEAU tab = newArray();
	printf("Le nombre d'elements dans le tableau est %d", tab.eltsCount); // Affichage du nombre d'�l�ments (valeurs non nulles dans le tableau)
	printf("\nLa taille du tableau est : %d", tab.size); // Affichage taille tableau
	displayElements(&tab, 1, 10); // Affichage tableau initial

	setElement(&tab, 1, 4);
	setElement(&tab, 3, 5);
	setElement(&tab, 12, 3); // Initialement, le tableau est de taille 10. Il est donc agrandi pour placer 3 en position 12 gr�ce � la fonction "incrementArraySize" dans la fonction "setElement".
	//printf("\n On ins�re 4 � la position 1, puis 5 � la position 3 puis 3 � la position 12");
	printf("\nIl y a %d elements dans le tableau", tab.eltsCount);
	printf("\nLa taille du tableau est de %d", tab.size);
	displayElements(&tab, 1, tab.size); // Affichage du tableau avec les 3 valeurs ajout�es

	setElement(&tab, 2, 2);
	setElement(&tab, 5, 8);
	setElement(&tab, 15, 12);
	setElement(&tab, 18, 20);
	setElement(&tab, 24, 24);

	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount); // Affichage du nombre d'�l�ments dans le tableau, comprenant les 5 valeurs ajout�es, + les 3 pr�c�dentes
	printf("\nLa taille du tableau est de %d", tab.size); // Affichage de la taille du tableau qui est d�sormais de 24, puisqu'un �l�ment se trouve en position 24.

	displayElements(&tab, 1, tab.size); // Affichage du tableau avec les 5 �l�ments ajout�s

	deleteElements(&tab, 2, 12);   // Suppression des �l�ments entre la 2�me et la 12�me valeur
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nLa taille du tableau est d�sormais de %d", tab.size); // Affichage de la nouvelle taille du tableau apr�s la suppression des �l�ments.
	displayElements(&tab, 1, tab.size); // Affichage du tableau apr�s la suppression des �l�ments
	setElement(&tab, 18, 5);
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nLa taille du tableau est de %d", tab.size);
	displayElements(&tab, 1, tab.size);
	deleteElements(&tab, 7, 4); // Suppression des �l�ments entre la 4�me et la 7�me valeur
	printf("\nLe nombre d'elements dans le tableau est : %d ", tab.eltsCount);
	printf(" \nLa taille du tableau est de %d", tab.size);
	displayElements(&tab, 1, tab.size); // Affichage du tableau
	printf("\nVoici l'affichage du tableau entre la position 9 et 14 :");
	displayElements(&tab, 9, 14); // Affichage du tableau entre la position 9 et 14
}