#pragma once

struct Node {
	int ID;
	Node *precedent, *suivant;
	Node(int i, Node *p, Node *s) : ID(i), precedent(p), suivant(s) {
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
		bool rechercheID(int);	// recherche dans la liste le int designe
		void afficher(bool);	// affiche la liste (true = depuis le debut, false = depuis la fin)
		void ajouterID(int);
		void ajouterPrecedent(Node*);
		void ajouterSuivant(Node*);
		void insertNodeApres(int);	// insert noeud apres debut
		void insertNodeAvant(int);	// insert noeud avant debut
		void insertNodeApresID(int, Node*);	// insert apres un noeud specifique
		void insertNodeAvantID(int, Node*);	// insert avant un noeud specifique
		void supprimerID(int, bool);
};

