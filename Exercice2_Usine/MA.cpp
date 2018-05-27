#include "stdafx.h"
#include "MA.h"
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;

MA::MA() {}
MA::~MA() {}

bool MA::TraiterPiece(Axe &a) {
	cout << "Axe :  Debut de traitement\n";
	if (a.getEstTraiter() == true) { return true; }	// La piece est deja traitée
	
	// Temps d'attente (en seconde)
	double tpsAttente = 2.5;

	// 25% de chance de tomber en panne
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "       Machine MA en panne...\n";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	// Usinage de la pièce
	a.setEstTraiter(true);
	cout << "       Fin de traitement.\n";
	
	return true;
}
bool MA::TraiterPiece(Jupe &j) { return false; }
bool MA::TraiterPiece(Tete &t) { return false; }
Piston * MA::TraiterPiece(Axe &a, Jupe &j, Tete &t) { return nullptr; }
