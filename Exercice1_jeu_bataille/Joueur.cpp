#include "stdafx.h"
#include "Joueur.h"
#include "Pile.cpp"
Joueur::Joueur()
{
}

Joueur::Joueur(Pile<Carte> deck)
{
	this->deck = deck;
	this->defausse = Pile<Carte>((deck.taille())*2);
}


Joueur::~Joueur()
{
}
