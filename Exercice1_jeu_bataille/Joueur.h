#pragma once
#include "Pile.h"
#include "Carte.h"


class Joueur
{
public:
	Joueur();
	Joueur(Pile<Carte> deck);
	~Joueur();
	Pile<Carte> deck;
	Pile<Carte> defausse;
	float score;
};

