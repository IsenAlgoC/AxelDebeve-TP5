#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#define TAB2SIZE 20;
#define TAILLEAJOUT 5;

int main() {
	// Déclaration des variables 
	int MyTab1[10]; int* MyTab2 = NULL; int tabSize = TAB2SIZE; int nbElts = 20;

	// Initalisation & affichage de MyTab1
	InitTab(MyTab1, 10);
	printf("Tab1 est :");
	afficheTab(MyTab1, 10, 6);

	// Allocation dynamique du tableau
	MyTab2 = (int*)malloc(sizeof(int) * tabSize);
	if (MyTab2 == NULL) {
		printf("Memoire insuffisante");
		exit(0);
	}

	// On initialise MyTab2 avec 20 zéros et on l'affiche

	InitTab(MyTab2, nbElts);
	printf(" \n Tab2 est :");
	afficheTab(MyTab2, 20, nbElts);

	// On effectue deux fois la fonction realloc à la suite puis affichage du tableau à la fin

	printf(" \n Le dernier element du tableau est %d", *(MyTab2 + nbElts - 1));
	ajouterElementDansTableau(MyTab2, &tabSize, &nbElts, 1);
	printf(" \n Le dernier element du tableau apres l'ajout est %d", *(MyTab2 + nbElts - 1));
	printf(" \n Il y a %d elements dans le tableau, la taille du tableau est de %d", nbElts, tabSize);
	ajouterElementDansTableau(MyTab2, &tabSize, &nbElts, 2);
	printf(" \n Le dernier element du tableau apres l'ajout est %d", *(MyTab2 + nbElts - 1));
	printf(" \n Il y a %d elements dans le tableau, la taille du tableau est de %d", nbElts, tabSize);
	afficheTab(MyTab2, tabSize, nbElts);
	free(MyTab2); // Plus besoin de MyTab2, on libère de l'espace
}