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
	int nbPiecesMax = 300;
	srand(time(NULL));

	Piece *tableau_carton[5] = { new Tete(), new Axe(), new Tete(), new Jupe() };
	//Utilities::genererCarton(nbPiecesMax);
	Utilities::trierCarton(tableau_carton);
	
	// Pause pour voir le resultat
	getchar();

	return 0;
}

