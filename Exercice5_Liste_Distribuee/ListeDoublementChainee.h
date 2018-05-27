#pragma once

struct Node {
	int data;
	Node *precedent, *suivant;
	Node(int d, Node *p, Node *s) : data(d), precedent(p), suivant(s) {
		if (p) precedent->suivant = this;
		if (s) suivant->precedent = this;
	}
};

class ListeDoublementChainee {
	public:
		ListeDoublementChainee(int);
		virtual ~ListeDoublementChainee();

		Node *debut;	// Pointe vers le noeud actuel
		int taille;

		bool estVide();
		bool rechercheData(int);	// recherche dans la liste le int designe
		void afficher(bool);		// affiche la liste (true = depuis le debut, false = depuis la fin)
		void ajouterData(int);
		void ajouterPrecedent(Node*);
		void ajouterSuivant(Node*);
		void insertNodeApres(int);	// insert noeud apres debut
		void insertNodeAvant(int);	// insert noeud avant debut
		void insertNodeApresData(int, Node*);	// insert apres un noeud specifique
		void insertNodeAvantData(int, Node*);	// insert avant un noeud specifique
		void supprimerData(int, bool);
};

