#pragma once
#include "Joueur.h"
#include <tuple>

using namespace std;
class Jeu
{
public:
	Jeu(Joueur joueur1, Joueur joueur2);
	~Jeu();
	void DemarrerBataille();
	void CalculScore(Joueur &J);
	Joueur J1;
	Joueur J2;
	bool log = false;
};

