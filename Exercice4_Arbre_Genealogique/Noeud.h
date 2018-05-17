#pragma once
using namespace std;
#include <iostream>  
template <typename T>
class Noeud
{
public:
	Noeud(Noeud &enfant);
	~Noeud();
private:
	Noeud * parent_gauche;
	Noeud *	parent_droit;
	Noeud * enfant;
};

