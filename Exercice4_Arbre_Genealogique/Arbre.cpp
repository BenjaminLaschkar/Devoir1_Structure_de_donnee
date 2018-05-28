#include "stdafx.h"
#include "Arbre.h"


Arbre::Arbre(Personne root_personne)
{
	Noeud* n_root = new Noeud();
	root = n_root;
	root->setPersonne(root_personne);
}


Arbre::~Arbre()
{
	freeNode(root);
}

// Free the node
void Arbre::freeNode(Noeud* leaf)
{
	if (leaf != NULL)
	{
		freeNode(leaf->Mother());
		freeNode(leaf->Father());
		delete leaf;
	}
}


// Add a node (private)

void Arbre::addNode(Personne personne, Noeud* leaf, Family family) {
	if (family == Mother) {
		Noeud * n = new Noeud();
		n->setPersonne(personne);
		leaf->setMother(n);
	}
	if (family == Father) {
		Noeud * n = new Noeud();
		n->setPersonne(personne);
		leaf->setFather(n);
	}
	taille++;
}


void Arbre::Preorder(Noeud* node)
{
	if (node)
	{
		cout << node->Key().prenom << " ";
		Preorder(node->Mother());
		Preorder(node->Father());
	}
}

void Arbre::Inorder(Noeud* Root)
{
	if (Root != NULL)
	{
		Inorder(Root->Mother());
		cout << Root->Key().prenom << " ";
		Inorder(Root->Father());

	}
}

void Arbre::Postorder(Noeud* Root)
{
	if (Root != NULL)
	{

		Postorder(Root->Mother());
		Postorder(Root->Father());
		cout << Root->Key().prenom << " ";

	}
}

int Arbre::getTaille() {
	return taille;
}

void Arbre::getCouleur(Noeud * node, Couleur couleur)
{
	if (node != NULL)
	{
		getCouleur(node->Mother(), couleur);
		getCouleur(node->Father(), couleur);
		if (node->Key().couleur == couleur) {
			cout << node->Key().prenom << " ";
		}
	}
}



void Arbre::getAge(Noeud* n) {
	// Create a queue
	queue<Noeud*> q;

	// Push the root
	q.push(n);
	float moyenne_age = 0;
	while (!q.empty())
	{
		// Dequeue a node from front
		Noeud* v = q.front();
		//cout << v->Key().prenom << " ";
		moyenne_age += 2018 - (float)v->Key().annee_de_naissance;
		// Enqueue the left children
		if (v->Mother() != NULL)
			q.push(v->Mother());

		// Enqueue the right children
		if (v->Father() != NULL)
			q.push(v->Father());

		// Pop the visited node
		q.pop();
	}
	cout << "la moyenne d'age est de " << moyenne_age / taille << " ans." << endl;
}