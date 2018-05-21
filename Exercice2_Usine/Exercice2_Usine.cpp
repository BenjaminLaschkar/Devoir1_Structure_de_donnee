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

	//Piece *tableau_carton[5] = { new Tete(), new Axe(), new Tete(), new Jupe() };
	//Utilities::trierCarton(tableau_carton);

	cout << "\n\n On fait des tests et on s'amuse \n\n";

	//Utilities::genererCarton(nbPiecesMax);
	//Utilities::trierCarton(tableau_carton2);

	// Pause pour voir le resultat
	getchar();

	return 0;
}

