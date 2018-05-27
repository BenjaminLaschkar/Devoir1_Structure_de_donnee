#include "stdafx.h"
#include "Personne.h"
#include <iostream>


Personne::Personne(const char * nom, const char * prenom, int annee_de_naissance, Couleur couleur)
{
	this->nom = nom;
	this->prenom = prenom;
	this->annee_de_naissance = annee_de_naissance;
	this->couleur = couleur;
}

Personne::~Personne()
{
}

