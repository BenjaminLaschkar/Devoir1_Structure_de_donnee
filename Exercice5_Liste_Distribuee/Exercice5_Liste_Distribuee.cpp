// Exercice5_Liste_Distribuee.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "ListeDoublementChainee.h"
#include <iostream>

using namespace std;

int main() {
	ListeDoublementChainee *liste;	// pointeur au début de liste
	Node *actuel;	// pointeur vers le noeur actuel de la liste
	char phrase[] = "azertyuiopqsdfghjklmwxcvbn";

	liste = new ListeDoublementChainee(phrase[0]);

	for (size_t i = 1; i < strlen(phrase); i++) { liste->insertNodeApres(phrase[i]); }

	liste->afficher(true);
	liste->afficher(false);

	getchar();
    return 0;
}

