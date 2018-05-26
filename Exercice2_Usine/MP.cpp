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
Piston* MP::TraiterPiece(Tete &t, Jupe &j, Axe &a) {
	cout << "Debut du traitement d'un piston. \n";
	Piston* p = new Piston();

	//TODO: D�finir la logique des pi�ces
	if (t.getEstTraiter() == false || j.getEstTraiter() == false || a.getEstTraiter() == false) { return p; }	//Toutes les pi�ces doivent �tres usin�es

	//TODO: 1- Temps d'attente (en minute)
	double tpsAttente = 1;

	//TODO: 2- Calculer temps supl�mentaire en v�rifiant si un nombre al�atoire entre 0 et 10 est compri entre 0 et 25 (25% de chance de tomber en panne)
	if (Utilities::getRandValue(0, 100) >= 0 && Utilities::getRandValue(0, 100) < 25) {
		cout << "Machine MP en panne...";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	//TODO: 3- Traitement de la pi�ce
	p->setEstTraiter(true);
	cout << "Fin du traitement d'un Piston. \n";
	
	return p;
}
