#include "stdafx.h"
#include "File.h"

template<typename T>
File<T>::File(const File<T>&f) {}

template <typename T>
File<typename T>::File(int max = 100) throw (bad_alloc) {
	tab = new T[max];
	tete = 0;
	queue = 0;
	cpt = 0;
	tailleMax = max;
}

template <typename T>
File<typename T>::~File() { delete[] tab; }

template<typename T>
void File<T>::enfiler(const T &e) {
	if (cpt<tailleMax) {
		tab[queue] = e;
		queue = (queue + 1) % tailleMax;
		cpt++;
	}
}

template <typename T>
T File<T> ::defiler() {
	if (cpt != 0) {
		T elementaDefiler = tab[tete];
		tete = (tete + 1) % tailleMax; //permet de « boucler » si on dépasse
		cpt--;
		return elementaDefiler;
	}
	else
		throw logic_error("Defiler: la file est vide!");
}

template<typename T>
int File<T>::taille() const { return cpt; }

template<typename T>
bool File<T>::estVide() const { return cpt==0; }

template<typename T>
bool File<T>::estPleine() const { return cpt==tailleMax; }

template<typename T>
const T & File<T>::premier() const {}

template<typename T>
const T & File<T>::dernier() const {}

template<typename T>
const File<T>& File<T>::operator=(const File<T>&f) {}
