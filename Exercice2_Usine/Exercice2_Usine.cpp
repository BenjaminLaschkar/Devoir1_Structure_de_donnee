// Exercice2.cpp : définit le point d'entrée pour l'application console.
#include "stdafx.h";
#include "Time.h";
#include <iostream>;
#include "Utilities.h";
#include "Piece.h"
#include "Tete.h";
#include "Axe.h";
#include "Jupe.h";
using namespace std;

int main()
{
	srand(time(NULL));
	int nbPiecesMax = 300;

	Piece *tableau_carton[5] = { new Tete(), new Axe(), new Tete(), new Jupe() };
	Utilities::trierCarton(tableau_carton);

	cout << "\n\n On fait des tests et on s'amuse \n\n";

	Utilities::genererCarton(nbPiecesMax);
	//Utilities::trierCarton(tableau_carton2);
		
	// Pause pour voir le resultat
	getchar();

	return 0;
}

