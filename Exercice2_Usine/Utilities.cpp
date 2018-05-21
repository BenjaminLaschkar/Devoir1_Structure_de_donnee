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

using namespace std;

Utilities::Utilities() { }

Utilities::~Utilities() { }

int Utilities::getRandValue(int inf, int sup) {
	int randValue = (rand() % sup) + inf;
	return randValue;
}

Piece Utilities::genererCarton(int nbPiecesMax) {
	Piece **tableauCarton = new Piece*[getRandValue(1, nbPiecesMax)];

	for (int i = 0; i < nbPiecesMax; i++) {
		int piece = getRandValue(1, 3);
		if (piece = 1) { tableauCarton[i] = new Tete(); }
		if (piece = 2) { tableauCarton[i] = new Axe();  }
		if (piece = 3) { tableauCarton[i] = new Jupe(); }
	}

	for (int index = 0; index < sizeof(tableauCarton); index++) {
		cout << " - ";
		cout << typeid(tableauCarton[index]).name();
		cout << "\n";
		if (typeid(tableauCarton[index]).name() == typeid(new Tete()).name()) { cout << "TETE\n"; }
		if (typeid(tableauCarton[index]).name() == typeid(new Axe()).name())  { cout << "AXE\n";  }
		if (typeid(tableauCarton[index]).name() == typeid(new Jupe()).name()) { cout << "JUPE\n"; }
	}
	return **tableauCarton;
}

void  Utilities::trierCarton(Piece *tableau_carton[5]) {
	//affecte les pièces de même nature à la file correspondante
	for (int index = 0; index < sizeof(tableau_carton); index++) {
		cout << " - ";
		cout << typeid(tableau_carton[index]).name();
		cout << "\n";
		if (typeid(tableau_carton[index]).name() == typeid(new Tete()).name()) { cout << "TETE\n"; }
		if (typeid(tableau_carton[index]).name() == typeid(new Axe()).name())  { cout << "AXE\n";  }
		if (typeid(tableau_carton[index]).name() == typeid(new Jupe()).name()) { cout << "JUPE\n"; }
	}
}
