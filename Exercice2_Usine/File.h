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

		// sélecteurs
		int taille() const;
		bool estVide() const;
		bool estPleine() const;
		const T& premier() const;
		const T& dernier() const;
		const File<T>& File<T>::operator = (const File<T>&f);

	private:
		T* tab;
		int tete;
		int queue;
		int tailleMax;
		int cpt;
};

