#include "stdafx.h"
#include "MP.h"
#include "Utilities.h";
#include "Windows.h";

MP::MP() {
}

MP::~MP() {
}

Piston* MP::TraiterPiece(Tete t, Jupe j, Axe a) {
	Piston* p = new Piston();
	//TODO: Définir la logique des pièces
	if (t.getEstTraiter() == false || j.getEstTraiter() == false || a.getEstTraiter() == false) {
		//Toutes les pièces doivent êtres usinées
		return p;
	}
	
	//TODO: 1 - Temps d'attente (en minute)
	double tpsAttente = 1;

	//TODO: 2- Calculer temps suplémentaire en vérifiant si un nombre aléatoire entre 0 et 10 est compri entre 0 et 25 (25% de chance de tomber en panne)
	if (Utilities::getRandValue(0, 100) >= 0 && Utilities::getRandValue(0, 100) < 25) {
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	//2 - Traitement de la pièce
	p->setEstTraiter(true);
	
	//TODO: 3 - 

	return p;
}
