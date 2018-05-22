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
/*
void Utilities::genererCarton(vector<Piece*> carton, int nbPiecesMax) {
	for (int i = 0; i < Utilities::getRandValue(1, nbPiecesMax); i++) {
		int typePiece = Utilities::getRandValue(1, 3);
		if (typePiece == 1) { carton.push_back(new Tete()); }
		if (typePiece == 2) { carton.push_back(new Axe()); }
		if (typePiece == 3) { carton.push_back(new Jupe()); }
	}
}
*/

/*
vector<Piece*> Utilities::supprimerCarton(vector<Piece*> carton) {
	for (int i = 0; i < carton.size(); ++i) {
		delete carton[i];
		carton[i] = 0;
	}

	return carton;
}*/
