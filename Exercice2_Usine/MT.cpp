#include "stdafx.h"
#include "MT.h"
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;

using namespace std;

MT::MT() {}
MT::~MT() {}

bool MT::TraiterPiece(Axe &a)  { return false; }
bool MT::TraiterPiece(Jupe &j) { return false; }
bool MT::TraiterPiece(Tete &t) {
	cout << "\nDebut de traitement d'une Tete. \n";
	if (t.getEstTraiter() == true) { return true; }	//La piece est deja traitée

	//TODO: 1 - Temps d'attente (en seconde)
	double tpsAttente = 2;

	//TODO: 2- Calculer temps suplémentaire en vérifiant si un nombre aléatoire entre 0 et 10 est compri entre 0 et 25 (25% de chance de tomber en panne)
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "Machine MT en panne. \n";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	//TODO: 3- Traitement de la pièce
	t.setEstTraiter(true);
	cout << "\nFin de traitement d'une Tete. \n";
	
	return true;
}
Piston * MT::TraiterPiece(Tete &t, Jupe &j, Axe &a) { return nullptr; }
