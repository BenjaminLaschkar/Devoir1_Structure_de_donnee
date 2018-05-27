#include "stdafx.h"
#include "MP.h"
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;

MP::MP() {}
MP::~MP() {}

bool MP::TraiterPiece(Axe &a) { return false; }
bool MP::TraiterPiece(Jupe &j) { return false; }
bool MP::TraiterPiece(Tete &t) { return false; }
Piston* MP::TraiterPiece(Axe &a, Jupe &j, Tete &t) {
	cout << "Piston : Debut du traitement\n";
	Piston* p = new Piston();
	
	// Condition de création
	if (a.getEstTraiter() == false || j.getEstTraiter() == false || t.getEstTraiter() == false) { return p; }

	// Temps d'attente (en minute)
	double tpsAttente = 1;

	// 25% de chance de tomber en panne
	if (Utilities::getRandValue(0, 100) >= 0 && Utilities::getRandValue(0, 100) < 25) {
		cout << "         Machine MP en panne...\n";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	// Usinage de la pièce
	p->setEstTraiter(true);
	cout << "         Fin du traitement d'un Piston.\n";
	return p;
}
