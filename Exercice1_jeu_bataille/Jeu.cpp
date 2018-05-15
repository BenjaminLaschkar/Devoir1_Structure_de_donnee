#include "stdafx.h"
#include "Jeu.h"
#include "Pile.cpp"

Jeu::Jeu(Joueur joueur1, Joueur joueur2)
{
		J1 = joueur1;
		J2 = joueur2;
}

Jeu::~Jeu()
{
}

void Jeu::DemarrerBataille()
{

	while (!(J1.deck.estVide()) && !(J2.deck.estVide())) {
		
		if (J1.deck.consulte_sommet().puissance > J2.deck.consulte_sommet().puissance) {

			J1.defausse.empiler(J1.deck.depiler());
			J1.defausse.empiler(J2.deck.depiler());
		}
		else if (J1.deck.consulte_sommet().puissance < J2.deck.consulte_sommet().puissance) {
			J2.defausse.empiler(J1.deck.depiler());
			J2.defausse.empiler(J2.deck.depiler());
		}
		else if (J1.deck.consulte_sommet().puissance == J2.deck.consulte_sommet().puissance) {
			if (J1.deck.consulte_sommet().couleur == J2.deck.consulte_sommet().couleur) {
				J1.defausse.empiler(J1.deck.depiler());
				J2.defausse.empiler(J2.deck.depiler());
			}
			else {
				if (J1.deck.consulte_sommet().couleur == true) {
					J1.defausse.empiler(J1.deck.depiler());
					J1.defausse.empiler(J2.deck.depiler());
				}
				else {
					J2.defausse.empiler(J1.deck.depiler());
					J2.defausse.empiler(J2.deck.depiler());
				}
			}
		}
	}
	
	CalculScore(J1);
	CalculScore(J2);

	
	if (J1.score > J2.score) {
		cout << "Le joueur J1 a gagne avec un score de " << J1.score << " contre un score de " << J2.score << " pour le joueur 2." << endl;
	}
	else if (J1.score  < J2.score) {
		cout << "Le joueur J2 a gagne avec un score de " << J2.score << " contre un score de " << J1.score << " pour le joueur 1." << endl;
	}
	else if (J1.score == J2.score) {
		cout << "Il y a egalité entre les joueurs avec un score de " << J1.score << " ." << endl;
	}

}

void Jeu::CalculScore(Joueur &J) {
	float multiplicateur_score = 1;

	while (!(J.defausse.estVide())) {
		if (J.defausse.consulte_sommet().couleur == true) {
			multiplicateur_score = 1.5;
		}
		else {
			multiplicateur_score = 1;
		}
		J.score += (float)(J.defausse.consulte_sommet().puissance)*(float)(J.defausse.consulte_sommet().bonus)*multiplicateur_score;
		J.defausse.depiler();
	}
}