#include "stdafx.h"
#include "MT.h"
#include "Utilities.h";
#include "Windows.h";

MT::MT() {
}

MT::~MT() {
}

bool MT::TraiterPiece(Tete t) {
	if (t.getEstTraiter() == true) {
		//La piece est deja traitée
		return true;
	}
	//TODO: Définir la logique des pièces

	//TODO: 1 - Temps d'attente (en minute)
	double tpsAttente = 2;

	//TODO: 2- Calculer temps suplémentaire en vérifiant si un nombre aléatoire entre 0 et 10 est compri entre 0 et 25 (25% de chance de tomber en panne)
	if (Utilities::getRandValue(0, 100) >= 0 && Utilities::getRandValue(0, 100) < 25) {
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente*1000);

	//2 - Traitement de la pièce
	t.setEstTraiter(true);
	
	//TODO: 3 - 

	return true;
}


