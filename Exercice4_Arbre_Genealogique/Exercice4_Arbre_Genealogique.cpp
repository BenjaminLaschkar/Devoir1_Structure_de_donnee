// Exercice4_Arbre_Genealogique.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Personne.h"
#include <iostream>
#include "Arbre.h"
using namespace std;

int main()
{
	
	Personne benjamin = Personne("Laschkar","Benjamin",1995, Marron);
	Personne pierre = Personne("Laschkar", "Pierre", 1953, Marron);
	Personne joelle = Personne("Laschkar", "Joelle", 1954, Marron);
	Personne sophie = Personne("Laschkar", "sophie", 1990, Marron);
	Personne suzanne = Personne("Laschkar", "Suzanne", 1918, Marron);
	Personne papouche = Personne("Laschkar", "Papouche", 1918, Marron);
	Personne andree = Personne("Ennouchy", "andree", 1918, Bleu);
	benjamin.AjouterPere(pierre);
	benjamin.AjouterMere(joelle);
	pierre.AjouterPere(papouche);
	pierre.AjouterMere(suzanne);
	joelle.AjouterMere(andree);
	
	deque <Personne* >::iterator i;
	deque <Personne *> hello = deque<Personne *>();
	hello.push_back(&sophie);
	hello.push_back(&benjamin);

	for (int j = 0; j < pierre.GetEnfants().size(); ++j) { cout << pierre.GetEnfants()[j]->annee_de_naissance; }

	Arbre famille = Arbre(benjamin);
	
	famille.ArbreAscendant(famille.noeud_racine);
	getchar();
}

