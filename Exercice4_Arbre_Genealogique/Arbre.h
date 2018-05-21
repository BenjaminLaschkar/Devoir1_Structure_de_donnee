#pragma once
#include "Noeud.h"
#include "Personne.h"
#include "Noeud.cpp"
class Arbre
{
public:
	Arbre(Noeud<Personne> racine);
	~Arbre();
	void ArbreAscendant();
	void ArbreDescendant();

private:
	Noeud<Personne> racine = Noeud<Personne>(nullptr);
};

