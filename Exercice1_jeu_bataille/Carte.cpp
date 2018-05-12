#include "stdafx.h"
#include "Carte.h"


Carte::Carte()
{
	this->puissance = rand() % 10 + 1;
	this->couleur = (0 == (rand() % 2));
	this->bonus = rand() % 4 + 1;
}


Carte::~Carte()
{
}
