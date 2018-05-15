#pragma once
using namespace std;
#include <iostream>  
template <typename T>
class Pile
{
public:
	Pile(int max = MAX_PILE) throw (bad_alloc);
	Pile(const Pile& p); //constructeur copie
	~Pile();
	void empiler(const T& e); 
	T depiler();
	//Sélecteurs
	bool estVide()const;
	int taille()const;
	const T consulte_sommet() const; // consulte l’élément au sommet
	//surcharge d'opérateurs
	const Pile<T>& operator = (const Pile<T>& p);
	template <typename U> friend std::ostream& operator<<
		(std::ostream& , const Pile<U>& );
private:
	T * tab;
	int sommet;  // indice de l’élément au sommet
	int tailleMax;
	static const int MAX_PILE = 100;

};

//Template obligatoirement dans le .h 
template<typename U>
inline std::ostream & operator<<(std::ostream &, const Pile<U>&)
{
	// TODO: insérer une instruction return ici
}
