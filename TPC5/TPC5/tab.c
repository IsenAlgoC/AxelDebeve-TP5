#include <stdio.h>
#include <stdlib.h>
#include "tab.h"
#define TAILLEAJOUT 5;


int InitTab(int* tab, int size) {
	if ((tab == NULL) || (size < 0)) {
		return(-1);
	}
	else {
		for (int i = 0; i < size; i++) {
			*(tab + i) = 0;
		}
		return(0);
	}
}


int afficheTab(int* tab, int size, int nbElts) {
	printf("\n");
	if (((nbElts > size) || (size < 0)) || (tab == NULL)) {
		printf("Impossible d'afficher le tableau");
		return(-1);
	}
	else {
		for (int i = 0; i < nbElts; i++) {
			printf("%d ", *(tab + i));
		}
		return(0);
	}
}


int* ajouterElementDansTableau(int* tab, int* size, int* nbElts, int element) {
	if ((tab != NULL) && (size != NULL) && (nbElts != NULL)) {
		if (*size > * nbElts) {                   // Si pas assez de place, pas de réalloc, ajout direct de la valeur élément au dernier élément 
			printf("\n Il y a assez de place");
			*(tab + *nbElts) = element;
			*nbElts = *nbElts + 1;
			return(tab);
		}
		else {
			printf(" \n Il n'y a plus de place");
			int ajout = TAILLEAJOUT;
			int* tmp = tab; // Sauvegarde du pointeur au cas où la réalloc échoue
			tab = (int*)realloc(tab, (*size + ajout) * (sizeof(int)));
			if (tab != NULL) { // Vérification de la réalloc. Si ça a fonctionné, on peut déplacer tab à l'adresse prévue et modifier les différents compteurs
								  // Cela  permet de ne pas modifier la valeur de tab si la réalloc n'a pas fonctionné
				*size = *size + TAILLEAJOUT;
				*(tab + *nbElts) = element;
				*nbElts = *nbElts + 1;
				return(tab);
			}
			else {
				tab = tmp;       // Si la réalloc n'a pas fonctionné, on récupère le pointeur d'origine
				printf("La reallocation n'a pas fonctionne correctement");
				return(NULL);
			}
		}
	}
}