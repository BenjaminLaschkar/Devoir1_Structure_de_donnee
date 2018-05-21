#pragma once
using namespace std;
#include <iostream>  
template <typename T>
class Noeud
{
public:
	Noeud(T* data);
	~Noeud();

	void SetParentGauche(Noeud* parent_gauche);
	void SetParentDroit(Noeud* parent_droit);
	void SetEnfant(Noeud* enfant);

	Noeud<T> * getParentGauche();
	Noeud<T> * getParentDroit();
	Noeud<T> * getEnfant();

	T * data;

private:
	Noeud<T> * parent_gauche;
	Noeud<T> *	parent_droit;
	Noeud<T> * enfant;
};

