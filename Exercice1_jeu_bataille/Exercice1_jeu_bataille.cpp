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

	// Récupération du nombre de carte
	cout << "Avec combien de cartes voulez vous jouer?" << endl;
	int nombreCarte;
	cin >> nombreCarte;


	// Creation de la pioche
	Pioche pioche = Pioche(nombreCarte);
	
	// Distribution des cartes
	tuple<Pile<Carte>, Pile<Carte >> decks = pioche.Distribuer();

	//Attribution des decks aux joueurs
	Joueur joueur1 = Joueur(get<0>(decks));
	Joueur joueur2 = Joueur(get<1>(decks));

	// Création du jeu
	Jeu jeu = Jeu(joueur1, joueur2);

	// Variable log à true si on veut les logs de bataille
	jeu.log = true;

	// Lancement du jeu
	jeu.DemarrerBataille();
	
	// Pause pour voir le resultat
	getchar();
	getchar();


}

