// Exercice1_jeu_bataille.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include <iostream>
#include "Pioche.h"


using namespace std;

int main()
{
	Pioche pioche = Pioche(5);
	tuple<Pile<Carte>, Pile<Carte >> decks = pioche.Distribuer();
	
	//Les deux decks sont les meme, pourquoi ??? Il y a une erreur quelque part mais ça compile
	get<0>(decks).consulte_sommet();
	get<1>(decks).consulte_sommet();


	getchar();


}

