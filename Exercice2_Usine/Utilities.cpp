#include "stdafx.h"
#include "Utilities.h"
#include "stdlib.h";
#include "Time.h";
#include "Math.h";
#include "Tete.h";
#include "Axe.h";
#include "Jupe.h";
#include <typeinfo>; // permet de comparer deux types d'objet
#include <iostream>;
using namespace std;
Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}

int Utilities::getRandValue(int inf, int sup)
{
	//ceil(nombre_aleatoire * 1.0 / RAND_MAX)*(borne_maximale-borne_minimale)+borne_minimale)
	return ceil(rand() * 1.0 / RAND_MAX) * (sup - inf) + inf;
}
void  Utilities::trierCarton(Piece *tableau_carton[5]) {
	//affecte les pièces de même nature à la file correspondante
	for (int index = 0; index < sizeof(tableau_carton); index++) {
		cout << " - ";
		cout << typeid(tableau_carton[index]).name();
		cout << "\n";
		if (typeid(tableau_carton[index]).name() == typeid(new Tete()).name()) {
			cout << "TETE\n";
		}
		if (typeid(tableau_carton[index]).name() == typeid(new Axe()).name()) {
			cout << "AXE\n";
		}
		if (typeid(tableau_carton[index]).name() == typeid(new Jupe()).name()) {
			cout << "JUPE\n";
		}
	}

}
