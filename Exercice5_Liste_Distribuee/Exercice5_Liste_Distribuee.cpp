// Exercice5_Liste_Distribuee.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "ListeDoublementChainee.h"
#include <iostream>
using namespace std;

int main() {
	ListeDoublementChainee *liste;	// pointeur au début de liste
	Node *actuel;	// pointeur vers le noeud actuel de la liste
	int numero[5] = { 1, 2, 3, 4, 5 };
	liste = new ListeDoublementChainee(numero[0]);

	for (int i = 1; i < 5; i++) { liste->insertNodeApres(numero[i]); }

	liste->afficher(true);
	liste->afficher(false);

	getchar();
    return 0;
}

// TODO
// Step 1 :
//		Liste doublement chaînée distribuée où chaque noeud possède deux pointeurs vers son prédécesseur et son successeur
// Step 2 :
//       Méthode send(int)
// Step 3 :
//       Classe thread ==> calculer la somme des id de tous les noeuds.