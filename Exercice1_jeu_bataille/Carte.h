#pragma once
#include <cstdlib>
class Carte
{
public:
	int puissance;
	int bonus;
	bool couleur; //True = Rouge
	Carte();
	Carte(const Carte&);
	~Carte();
};

