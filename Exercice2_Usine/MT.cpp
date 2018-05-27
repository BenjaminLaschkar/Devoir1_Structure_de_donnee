#include "stdafx.h"
#include "MT.h"
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;

MT::MT() {}
MT::~MT() {}


bool MT::TraiterPiece(Axe &a) { return false; }
bool MT::TraiterPiece(Jupe &j) { return false; }
bool MT::TraiterPiece(Tete &t) {
	cout << "Tete : Debut de traitement\n";
	if (t.getEstTraiter() == true) { return true; }	// La piece est deja traitée

	// Temps d'attente (en seconde)
	double tpsAttente = 2;

	// 25% de chance de tomber en panne
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "       Machine MT en panne... \n";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	// Usinage de la pièce
	t.setEstTraiter(true);
	cout << "       Fin de traitement. \n";
	
	return true;
}
Piston * MT::TraiterPiece(Axe &a, Jupe &j, Tete &t) { return nullptr; }
