#include "stdafx.h"
#include "Carte.h"


Carte::Carte()
{
	this->puissance = rand() % 10 + 1;
	this->couleur = (0 == (rand() % 2));
	this->bonus = rand() % 4 + 1;
}

Carte::Carte(const Carte& carte) {
	this->puissance = carte.puissance;
	this->couleur = carte.couleur;
	this->bonus = carte.bonus;
}

Carte::~Carte()
{
}
	