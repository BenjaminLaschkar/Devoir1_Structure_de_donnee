#include "stdafx.h"
#include "Utilities.h"
#include "stdlib.h";
#include "Time.h";
#include "Math.h";
#include "Tete.h";
#include "Axe.h";
#include "Jupe.h";
#include <typeinfo>; // permet de comparer deux types d'objet
#include <iostream>;
#include <vector>

using namespace std;
Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}

int Utilities::getRandValue(int inf, int sup) {
	int randValue = (rand() % sup) + inf;
	return randValue;
}

Piece Utilities::genererCarton(int nbPiecesMax) {
	Piece **tableauCarton = new Piece*[getRandValue(1, nbPiecesMax)];
	/*
	for (int i = 0; i < nbPiecesMax; i++) {
	int piece = getRandValue(1, 3);
	if (piece == Tete) { tableauCarton[i] = new Tete(); }
	if (piece == Axe) { tableauCarton[i] = new Axe(); }
	if (piece == Jupe) { tableauCarton[i] = new Jupe(); }
	}*/

	return **tableauCarton;
}

void  Utilities::trierCarton(std::vector<Piece*> tab) {
	//affecte les pièces de même nature à la file correspondante  for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
	//int size = sizeof(tableau_carton) / sizeof(*tableau_carton);
	/*for (int index = 0; index < size; index++) {
		

		if (typeid(tableau_carton[index]) == typeid(new Tete())) {
			cout << "TETE\n";
		}
		else if (typeid(tableau_carton[index]) == typeid(new Axe())) {
			cout << "AXE\n";
		}
		else if (typeid(tableau_carton[index]) == typeid(new Jupe())) {
			cout << "JUPE\n";
		}
		else if (typeid(tableau_carton[index]) == typeid(new Piece())) {
			cout << "PIECE\n";
		}
	}*/

	for (std::vector<Piece*>::iterator it = tab.begin(); it != tab.end(); ++it) {
		cout << typeid(**it).name();
		
	}

}
