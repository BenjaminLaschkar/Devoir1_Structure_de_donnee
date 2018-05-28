#include <iostream>
#pragma once
using namespace std;

template <typename T>
class File {
	public:
		File(int max = 100) throw (bad_alloc);
		~File();
		File(const File <T> &f);
		
		void enfiler(const T &e);
		T defiler();
		
		int taille() const;
		bool estVide() const;
		bool estPleine() const;
		const T& premier() const; // tête de la file
		const T& dernier() const; // queue de la file
		const File<T>& File<T>::operator = (const File<T>&f);
		
	private:
		T* tab;
		int tete;
		int queue;
		int tailleMax;
		int cpt;
};

