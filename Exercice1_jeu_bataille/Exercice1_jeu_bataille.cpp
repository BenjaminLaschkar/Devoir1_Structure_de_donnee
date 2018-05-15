// Exercice1_jeu_bataille.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "Pioche.h"
#include "Joueur.h"
#include "Jeu.h"

using namespace std;

int main()
{
	// Creation de la pioche
	Pioche pioche = Pioche(50);
	//jusque la la puissance marche

	
	// Distribution des cartes
	tuple<Pile<Carte>, Pile<Carte >> decks = pioche.Distribuer();

	//Attribution des decks aux joueurs
	Joueur joueur1 = Joueur(get<0>(decks));
	Joueur joueur2 = Joueur(get<1>(decks));

	// Lancement du jeu
	Jeu jeu = Jeu(joueur1, joueur2);
	jeu.DemarrerBataille();
	
	getchar();


}

