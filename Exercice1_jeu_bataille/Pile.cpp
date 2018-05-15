#include "stdafx.h"
#include "Pile.h"

//Constructeur
template<typename T>
Pile<T>::Pile(int max) throw (bad_alloc)
{
	tab = new T[max];
	sommet = -1;
	tailleMax = max;
}

//Constructeur de copie
template<typename T>
Pile<T>::Pile(const Pile & p)
{
	tab = new T[p.tailleMax];
	tailleMax = p.tailleMax;
	for (int i = 0; i< tailleMax; i += 1)
		tab[i] = p.tab[i];
	sommet = p.sommet;
}

//Destructeur thanos
template <typename T>
Pile<T>::~Pile()
{
	delete[] tab;
}

template<typename T>
void Pile<T>::empiler(const T& e) throw (std::length_error)
{
	if (sommet + 1 < tailleMax)
	{
		sommet += 1; // a += b -> a = a+ b
		tab[sommet] = e;
	}
	else
		throw length_error("Empiler:la pile est pleine\n");
}

template<typename T>
T Pile<T>::depiler() throw (std::logic_error)
{
	if (!estVide()) return tab[sommet--];
	else
		throw logic_error("Depiler: la pile est vide!");
}

template<typename T>
bool Pile<T>::estVide() const
{
	return (sommet == -1);
}

template<typename T>
int Pile<T>::taille() const
{
	return tailleMax;
}

template<typename T>
const T  Pile<T>::consulte_sommet() const
{
	return tab[sommet];
}

template<typename T>
const Pile<T>& Pile<T>::operator=(const Pile<T>& p) throw (bad_alloc)
{
	if (tab != 0) delete[] tab; //on nettoie l’objet qu’on veux écraser
	tab = new T[p.tailleMax];
	tailleMax = p.tailleMax;
	for (int i = 0; i< tailleMax; i += 1)
		tab[i] = p.tab[i];
	sommet = p.sommet;
	return (*this);
}
