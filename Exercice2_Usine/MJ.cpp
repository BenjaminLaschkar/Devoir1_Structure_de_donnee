#include "stdafx.h";
#include "MJ.h";
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;

MJ::MJ() {}
MJ::~MJ() {}

bool MJ::TraiterPiece(Axe &a) { return false; }
bool MJ::TraiterPiece(Jupe &j) {
	cout << "Jupe : Debut de traitement d'une Jupe. \n";
	if (j.getEstTraiter() == true) { return true; }	// La piece est deja traitée

	// Temps d'attente (en seconde)
	double tpsAttente = 3;

	// 25% de chance de tomber en panne
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "       Machine MJ en panne...\n";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	// Usinage de la pièce
	j.setEstTraiter(true);
	cout << "       Fin de traitement.\n";

	return true;
}
bool MJ::TraiterPiece(Tete &t) { return false; }
Piston * MJ::TraiterPiece(Axe &a, Jupe &j, Tete &t) { return nullptr; }
