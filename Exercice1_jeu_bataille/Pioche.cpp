#include "stdafx.h"
#include "Pioche.h"


Pioche::Pioche(int nombre_de_carte_par_joueur)
{
	if (nombre_de_carte_par_joueur > 50) {
		throw("erreur : nombre de carte > 50");
	}
	this->nombre_de_carte_par_joueur = nombre_de_carte_par_joueur;
	srand(time(NULL));
	pioche = Pile<Carte>();
	for (int i = 0; i < MAX_CARTE; i++) {
		Carte carte  = Carte();
		pioche.empiler(carte);
	}
}


Pioche::~Pioche()
{
}


tuple<Pile<Carte>, Pile<Carte>> Pioche::Distribuer()
{
	Pile<Carte> deck_1 = Pile<Carte>(this->nombre_de_carte_par_joueur);
	Pile<Carte> deck_2 = Pile<Carte>(this->nombre_de_carte_par_joueur);

	for (int i = 0; i < this->nombre_de_carte_par_joueur; i++) {
		deck_1.empiler(pioche.consulte_sommet());
		pioche.depiler();
		deck_2.empiler(pioche.consulte_sommet());
		pioche.depiler();
	}
	
	tuple<Pile<Carte>, Pile<Carte>> decks(deck_1, deck_2);
	return decks;
}
