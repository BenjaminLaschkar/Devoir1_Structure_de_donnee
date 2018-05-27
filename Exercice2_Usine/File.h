#pragma once
using namespace std;
#include <iostream>  
template <typename T>
class File
{
public: // constructeurs et destructeurs:
	File(int max = 100) throw (bad_alloc);
	~File();
	File(const File <T> &f);
	// modificateurs
	void enfiler(const T &e);
	T defiler();
	// s�lecteurs
	int taille() const;
	bool estVide() const;
	bool estPleine() const;
	const T& premier() const; // t�te de la file
	const T& dernier() const; // queue de la file
	// surcharges d'op�rateurs 
	const File<T>& File<T>::operator = (const File<T>&f);
	//template <typename U> friend std::ostream& operator() << (std::ostream& f, const File<U>& q);
private:
	T* tab;
	int tete;
	int queue;
	int tailleMax;
	int cpt;
};

