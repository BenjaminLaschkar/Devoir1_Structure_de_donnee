#include "stdafx.h"
#include "Pioche.h"
#include <time.h>
#include <iostream>
#include "Carte.h"
#include "Pile.h"
#include "Pile.cpp" //Afin d'éviter le LNK2019 il faut compiler les librairie utilisant un template : https://stackoverflow.com/questions/3705740/c-lnk2019-error-unresolved-external-symbol-template-classs-constructor-and

using namespace std;

Pioche::Pioche(int nombre_de_carte)
{

	srand(time(NULL));

	Pile<Carte> pioche = Pile<Carte>(nombre_de_carte);

	for (int i = 0; i < nombre_de_carte; i++) {
		Carte carte  = Carte();
		pioche.empiler(carte);
	}
	int a = 1;
	
}


Pioche::~Pioche()
{
}
