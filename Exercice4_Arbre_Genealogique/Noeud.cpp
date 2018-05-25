#include "stdafx.h"
#include "Noeud.h"

template <typename T>
Noeud<T>::Noeud(T* data)
{
	this->data = data;
}

template <typename T>
Noeud<T>::~Noeud()
{
}

template<typename T>
void Noeud<T>::SetParentGauche(Noeud<T> * parent_gauche)
{
	this->parent_gauche = parent_gauche;

}
template<typename T>
void Noeud<T>::SetParentDroit(Noeud<T> * parent_droit)
{
	this->parent_droit = parent_droit;
}

template<typename T>
void Noeud<T>::SetEnfant(Noeud<T> * enfant)
{
	this->enfant = enfant;
}

template<typename T>
Noeud<T> & Noeud<T>::getParentGauche()
{
	return *this->parent_gauche;
}

template<typename T>
Noeud<T> &  Noeud<T>::getParentDroit()
{
	return *this->parent_droit;
}

template<typename T>
Noeud<T> &  Noeud<T>::getEnfant()
{
	return * this->enfant;
}

