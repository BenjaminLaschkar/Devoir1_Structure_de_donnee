#include "stdafx.h"
#include "stdlib.h";
#include "Axe.h";
#include "File.h";
#include "Jupe.h";
#include "Math.h";
#include "Tete.h";
#include "Time.h";
#include "Utilities.h"
#include <iostream>;
#include <typeinfo>;
#include <vector>
using namespace std;

Utilities::Utilities() {}
Utilities::~Utilities() {}

int Utilities::getRandValue(int inf, int sup) {
	int randValue = (rand() % sup) + inf;
	return randValue;
}

vector<Piece*> Utilities::genererCarton(int nbPiecesMax) {
	vector<Piece*> carton;
	for (int i = 0; i < Utilities::getRandValue(1, nbPiecesMax); i++) {
		int typePiece = Utilities::getRandValue(1, 3);
		if (typePiece == 1) { carton.push_back(new Axe()); }
		if (typePiece == 2) { carton.push_back(new Jupe()); }
		if (typePiece == 3) { carton.push_back(new Tete()); }
	}
	return carton;
}
void Utilities::supprimerCarton(vector<Piece*> &carton) {
	for (int i = 0; i < carton.size(); ++i) {
		delete carton[i];
		carton[i] = 0;
	}
}
void Utilities::trieCarton(vector<Piece*> &carton, File<Axe> &fAxe, File<Jupe> &fJupe, File<Tete> &fTete) {
	cout << "La taille du carton est de : \"";
	cout << carton.size();
	cout << "\" elements\n" << endl;

	for (int i = 0; i<carton.size(); ++i) {
		if (carton[i]->estAxe() == true) {
			cout << "Axe     ";
			Axe a = Axe();
			fAxe.enfiler(a);
		}
		if (carton[i]->estJupe() == true) {
			cout << "Jupe    ";
			Jupe j = Jupe();
			fJupe.enfiler(j);
		}
		if (carton[i]->estTete() == true) {
			cout << "Tete    ";
			Tete t = Tete();
			fTete.enfiler(t);
		}
	}
	cout << "\n" << endl;
}

