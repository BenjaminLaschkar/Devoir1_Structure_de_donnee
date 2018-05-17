#include "stdafx.h"
#include "Noeud.h"

template <typename T>
Noeud<T>::Noeud(Noeud &enfant)
{
	this->enfant = enfant;
}

template <typename T>
Noeud<T>::~Noeud()
{
}
