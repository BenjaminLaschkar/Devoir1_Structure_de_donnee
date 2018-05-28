#include "stdafx.h"
#include "MP.h"
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;

MP::MP() {}
MP::~MP() {}

bool MP::TraiterPiece(Axe &a)  { return false; }
bool MP::TraiterPiece(Jupe &j) { return false; }
bool MP::TraiterPiece(Tete &t) { return false; }
Piston* MP::TraiterPiece(Tete &t, Jupe &j, Axe &a) {
	cout << "Debut du traitement d'un piston." << endl;
	Piston* p = new Piston();

	// Toutes les pieces doivent être traitees
	if (t.getEstTraiter() == false || j.getEstTraiter() == false || a.getEstTraiter() == false) { return p; }

	// Temps d'attente (en minute)
	double tpsAttente = 1;

	//25% de chance de tomber en panne
	int rand = Utilities::getRandValue(1, 100);
	if ( rand >= 0 && rand < 25) {
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
		cout << "Machine MP en panne, Patientez !" << endl;
	}
	Sleep(tpsAttente * 1000);

	// Traitement de la pièce
	p->setEstTraiter(true);
	cout << "Fin du traitement d'un Piston." << endl;
	return p;
}
