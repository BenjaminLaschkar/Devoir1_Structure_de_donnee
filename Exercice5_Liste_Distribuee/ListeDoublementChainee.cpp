#include "stdafx.h"
#include "ListeDoublementChainee.h"
#include <iostream>

using namespace std;

ListeDoublementChainee::ListeDoublementChainee(int i) {
	debut = new Node(i, NULL, NULL);
	debut->suivant = debut->precedent = debut;
	taille = 1;
}
ListeDoublementChainee::~ListeDoublementChainee() {
	Node *tmp = this->debut;
	Node *temp;

	while (tmp->precedent) { tmp = tmp->precedent; }
	while (tmp) {
		temp = tmp->suivant;
		delete tmp;
		tmp = temp;
	}
	tmp = temp = NULL;
}

bool ListeDoublementChainee::estVide() { return (this->taille == 0); }
bool ListeDoublementChainee::rechercheID(int cherche) {
	int compteur = 0;
	Node *tmp = debut;

	while (tmp->suivant != debut) {
		if (tmp->ID == cherche) compteur++;
		tmp = tmp->suivant;
	}

	if (compteur > 0) {
		cout << "'" << cherche << "' a été trouvé " << compteur << " fois." << endl;
		return true;
	} else {
		cout << "'" << cherche << "' n'a pas été trouvé" << endl;
		return false;
	}
}
void ListeDoublementChainee::afficher(bool dir) {
	if (dir) {
		Node *tmp = debut;
		do {
			cout << tmp->ID;
			tmp = tmp->precedent;
		} while (tmp != debut);
	} else {
		Node *tmp = debut->suivant;
		do {
			cout << tmp->ID;
			tmp = tmp->suivant;
		} while (tmp != debut->suivant);
	}
	cout << endl;
}
void ListeDoublementChainee::ajouterID(int ID) { this->debut->ID = ID; }
void ListeDoublementChainee::ajouterPrecedent(Node* Precedent) { this->debut->precedent = Precedent; }
void ListeDoublementChainee::ajouterSuivant(Node* Suivant) { this->debut->suivant = Suivant; }
void ListeDoublementChainee::insertNodeApres(int i) {
	Node *s = debut->suivant;
	Node *p = debut;
	Node *temp = new Node(i, p, s);
	taille++;
}
void ListeDoublementChainee::insertNodeAvant(int i) {
	Node *s = debut;
	Node *p = debut->precedent;
	Node *temp = new Node(i, p, s);
	taille++;
}
void ListeDoublementChainee::supprimerID(int Cherche, bool all) {	// si vrai, il supprime tous les noeuds comprenant la recherche
	Node *tmp = debut;													// si faux, il supprime uniquement le premier noeud

	while (tmp) {
		if (tmp->ID == Cherche) {
			cout << "Suppression " << Cherche << endl;
			tmp->precedent->suivant = tmp->suivant;
			tmp->suivant->precedent = tmp->precedent;
			if (false) return;
		}
		tmp = tmp->suivant;
	}
}
