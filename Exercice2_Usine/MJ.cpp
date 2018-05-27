#include "stdafx.h";
#include "MJ.h";
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;

MJ::MJ() {}
MJ::~MJ() {}

bool MJ::TraiterPiece(Axe &a)  { return false; }
bool MJ::TraiterPiece(Jupe &j) {
	cout << "Debut de traitement d'une Jupe." << endl;
	if (j.getEstTraiter() == true) { return true; } // La piece est deja traitee

	// Temps d'attente (en seconde)
	double tpsAttente = 3;

	// 25% de chance de tomber en panne
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "Machine MJ en panne." << endl;
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	// Traitement de la pièce
	j.setEstTraiter(true);
	cout << "Fin de traitement d'une Jupe. \n" << endl;
	return true;
}
bool MJ::TraiterPiece(Tete &t) { return false; }
Piston * MJ::TraiterPiece(Tete &t, Jupe &j, Axe &a) { return nullptr; }
