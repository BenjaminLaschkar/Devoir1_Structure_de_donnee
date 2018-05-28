#pragma once
#include "Noeud.h"
#include "Personne.h"
#include <iostream>
static int taille = 1;
using namespace std;
enum Family { Father, Mother };
class Arbre
{
	Noeud* root;

public:
	Arbre(Personne root_personne);
	~Arbre();
	Noeud* Root() { return root; };
	void getAge(Noeud* noeud);
	void Inorder(Noeud*  noeud);
	void Postorder(Noeud* noeud);
	void Preorder(Noeud* noeud);
	int getTaille();
	void getCouleur(Noeud * noeud, Couleur couleur);

	//private:
	void addNode(Personne personne, Noeud* leaf, Family family);
	void freeNode(Noeud* leaf);
};

