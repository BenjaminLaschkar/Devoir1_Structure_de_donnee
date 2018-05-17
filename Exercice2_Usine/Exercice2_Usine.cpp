// Exercice2.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h";
#include <iostream>;
#include "Utilities.h";
#include "Piece.h"
#include "Tete.h";
#include "Axe.h";
#include "Jupe.h";
using namespace std;

int main()
{
	Piece *tableau_carton[5] = { new Tete(), new Axe(), new Tete(), new Jupe() };
	Utilities::trierCarton(tableau_carton);

	return 0;
}

