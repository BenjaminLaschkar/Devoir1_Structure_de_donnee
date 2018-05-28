#include "stdafx.h"
#include "MA.h"
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;

MA::MA() {}
MA::~MA() {}

bool MA::TraiterPiece(Axe &a)  {
	cout << "Debut de traitement d'un axe." << endl;

	if (a.getEstTraiter() == true) { return true; }	// La piece est deja traitee
	
	// Temps d'attente (en seconde)
	double tpsAttente = 2.5;

	// 25% de chance de tomber en panne
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "Machine MA en panne." << endl;
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	// Traitement de la pièce
	a.setEstTraiter(true);
	cout << "Fin de traitement d'un axe. \n" << endl;
	return true;
}
bool MA::TraiterPiece(Jupe &j) { return false; }
bool MA::TraiterPiece(Tete &t) { return false; }
Piston * MA::TraiterPiece(Tete &t, Jupe &j, Axe &a) { return nullptr; }
