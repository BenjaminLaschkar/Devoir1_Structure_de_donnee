#include "stdafx.h"
#include "ListeDoublementChainee.h"
#include <iostream>

using namespace std;

ListeDoublementChainee::ListeDoublementChainee(char d) {
	debut = new Node(d, NULL, NULL);
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
bool ListeDoublementChainee::rechercheData(char cherche) {
	int compteur = 0;
	Node *tmp = debut;

	while (tmp->suivant != debut) {
		if (tmp->data == cherche) compteur++;
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
			cout << tmp->data;
			tmp = tmp->suivant;
		} while (tmp != debut);
	} else {
		Node *tmp = debut;
		do {
			cout << tmp->data;
			tmp = tmp->precedent;
		} while (tmp != debut);
	}
	cout << endl;
}
void ListeDoublementChainee::ajouterData(char Data) { this->debut->data = Data; }
void ListeDoublementChainee::ajouterPrecedent(Node* Precedent) { this->debut->precedent = Precedent; }
void ListeDoublementChainee::ajouterSuivant(Node* Suivant) { this->debut->suivant = Suivant; }
void ListeDoublementChainee::insertNodeApres(char d) {
	Node *s = debut->suivant;
	Node *p = debut;
	Node *temp = new Node(d, p, s);
	taille++;
}
void ListeDoublementChainee::insertNodeAvant(char d) {
	Node *s = debut;
	Node *p = debut->precedent;
	Node *temp = new Node(d, p, s);
	taille++;
}
void ListeDoublementChainee::supprimerData(char Cherche, bool all) {	// si vrai, il supprime tous les noeuds comprenant la recherche
	Node *tmp = debut;													// si faux, il supprime uniquement le premier noeud

	while (tmp) {
		if (tmp->data == Cherche) {
			cout << "Suppression " << Cherche << endl;
			tmp->precedent->suivant = tmp->suivant;
			tmp->suivant->precedent = tmp->precedent;
			if (false) return;
		}
		tmp = tmp->suivant;
	}
}
