// Exercice4_Arbre_Genealogique.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "Personne.h"
#include "Arbre.h"


using namespace std;

int main()
{
	//Création des personnes de la famille Simpson
	const Personne abraham = Personne("Simpson", "Abraham", 1935, Marron);
	const Personne mona = Personne("Simpson", "Mona", 1932, Bleu);
	const Personne homer = Personne("Simpson", "Homer", 1979, Bleu);
	const Personne marge = Personne("Bouvier", "Marge", 1984, Marron);
	const Personne bart = Personne("Simpson", "Bart", 2008, Bleu);
	const Personne jacky = Personne("Bouvier", "Jacky", 1928, Marron);
	const Personne clancy = Personne("Bouvier", "Clancy", 1930, Marron);

	//On crée l'arbre à partir de bart
	Arbre arbre = Arbre(bart);

	//On ajoute les parents de bart
	arbre.addNode(homer, arbre.Root(), Father);
	arbre.addNode(marge, arbre.Root(), Mother);

	//On ajoute les grands parent paternel de bart
	arbre.addNode(abraham, arbre.Root()->Father(), Father);
	arbre.addNode(mona, arbre.Root()->Father(), Mother);

	//On ajoute les grands parent maternel de bart
	arbre.addNode(clancy, arbre.Root()->Mother(), Father);
	arbre.addNode(jacky, arbre.Root()->Mother(), Mother);

	//PreOrder
	cout << "PREORDER" << endl;
	arbre.Preorder(arbre.Root());
	cout << endl << endl;

	//InOrder
	cout << "INORDER" << endl;
	arbre.Inorder(arbre.Root());
	cout << endl << endl;

	//PostOrder
	cout << "POSTORDER" << endl;
	arbre.Postorder(arbre.Root());
	cout << endl << endl;

	//Taille
	cout << "La taille de l'arbre est de " << arbre.getTaille() << endl << endl;

	//Couleur des yeux
	cout << "Les personnes qui ont la couleur bleu sont : ";
	arbre.getCouleur(arbre.Root(), Bleu);
	cout << endl << endl;

	// Obtenir l'age moyen 
	arbre.getAge(arbre.Root());
	cout << endl << endl;

	getchar();
}

