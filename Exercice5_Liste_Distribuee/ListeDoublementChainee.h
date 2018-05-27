#pragma once

struct Node {
	char data;
	Node *precedent, *suivant;
	Node(char d, Node *p, Node *s) : data(d), precedent(p), suivant(s) {
		if (p) precedent->suivant = this;
		if (s) suivant->precedent = this;
	}
};

class ListeDoublementChainee {
	public:
		ListeDoublementChainee(char);
		virtual ~ListeDoublementChainee();

		Node *debut;	// Pointe vers le noeud actuel
		char taille;

		bool estVide();
		bool rechercheData(char);	// recherche dans la liste le char designe
		void afficher(bool);		// affiche la liste (true = depuis le debut, false = depuis la fin)
		void ajouterData(char);
		void ajouterPrecedent(Node*);
		void ajouterSuivant(Node*);
		void insertNodeApres(char);	// insert noeud apres debut
		void insertNodeAvant(char);	// insert noeud avant debut
		void insertNodeApresData(char, Node*);	// insert apres un noeud specifique
		void insertNodeAvantData(char, Node*);	// insert avant un noeud specifique
		void supprimerData(char, bool);
};

