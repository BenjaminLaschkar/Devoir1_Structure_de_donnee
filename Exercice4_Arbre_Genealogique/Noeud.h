#pragma once
#include <iostream>
#include <queue>
#include "Personne.h"
using namespace std;

class Noeud
{
	Personne personne = Personne("null", "null", 0, Marron);
	Noeud* mother;
	Noeud* father;
public:
	Noeud() { mother = NULL; father = NULL; };
	void setPersonne(Personne set_personne) { personne.nom = set_personne.nom; personne.prenom = set_personne.prenom; personne.annee_de_naissance = set_personne.annee_de_naissance; personne.couleur = set_personne.couleur; };
	void setMother(Noeud* aLeft) { mother = aLeft; };
	void setFather(Noeud* aRight) { father = aRight; };
	Personne Key() { return personne; };
	Noeud* Mother() { return mother; };
	Noeud* Father() { return father; };
};


