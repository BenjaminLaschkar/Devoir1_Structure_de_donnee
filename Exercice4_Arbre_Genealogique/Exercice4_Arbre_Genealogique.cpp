// Exercice4_Arbre_Genealogique.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "Personne.h"
#include <iostream>
using namespace std;

int main()
{
	
	Personne benjamin = Personne("Laschkar","Benjamin",1995, Marron);
	Personne pierre = Personne("Laschkar", "Pierre", 1953, Marron);
	Personne joelle = Personne("Laschkar", "Joelle", 1954, Marron);
	Personne sophie = Personne("Laschkar", "sophie", 1990, Marron);
	benjamin.AjouterPere(pierre);
	pierre.AjouterEnfant(benjamin);
	pierre.AjouterEnfant(sophie);
	pierre.AjouterFemme(joelle);
	joelle.AjouterEnfant(benjamin);
	joelle.AjouterEnfant(sophie);
	benjamin.AjouterMere(joelle);

	
	deque <Personne* >::iterator i;
	deque <Personne *> hello = deque<Personne *>();
	hello.push_back(&sophie);
	hello.push_back(&benjamin);

	for (int j = 0; j < pierre.GetEnfants().size(); ++j) cout<< pierre.GetEnfants()[j]->annee_de_naissance;


	getchar();
}

