#pragma once
#include "Noeud.h"
#include "Personne.h"
#include "Noeud.cpp"
class Arbre
{
public:
	Arbre(Personne personne_racine);
	~Arbre();
	void ArbreAscendant(Noeud<Personne> &actual_node);
	void ArbreDescendant();
	Noeud<Personne> noeud_racine = nullptr;
};

