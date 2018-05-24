// Exercice2_Usine.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h";
#include <iostream>;
#include <vector>

#include "Utilities.h";
#include "Piece.h"
#include "Tete.h";
#include "Axe.h";
#include "Jupe.h";
#include "Machine.h";
#include "MT.h";
#include "File.h";
#include "File.cpp"
#include "time.h"

using namespace std;

int main() {
	srand(time(NULL));
	int nbPiecesMax = 300;

	vector<Piece*> carton;

	carton = Utilities::genererCarton(carton, nbPiecesMax);
	
	Utilities::trieCarton(carton);
	Utilities::supprimerCarton(carton);

	
	// Pause pour voir le resultat
	getchar();

	return 0;
}
