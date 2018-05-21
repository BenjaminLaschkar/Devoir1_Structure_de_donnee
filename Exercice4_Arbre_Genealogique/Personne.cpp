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

void Personne::AjouterFemme(Personne & femme)
{
	this->femme = &femme;
}

void Personne::AjouterEnfant(Personne & enfant)
{
	
	this->liste_enfant.push_back(&enfant);
}

void Personne::AjouterPere(Personne & pere)
{
	this->pere = &pere;

}

void Personne::AjouterMere(Personne & mere)
{
	this->mere = &mere;
}

Personne * Personne::GetFemme()
{
	return this->femme;
}

deque<Personne *> Personne::GetEnfants()
{
	return liste_enfant;
}

Personne * Personne::GetPere()
{
	return this->pere;
}

Personne * Personne::GetMere()
{
	return this->mere;
}

