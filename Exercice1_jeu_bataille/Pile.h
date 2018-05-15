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
	//S�lecteurs
	bool estVide()const;
	int taille()const;
	const T consulte_sommet() const; // consulte l��l�ment au sommet
	//surcharge d'op�rateurs
	const Pile<T>& operator = (const Pile<T>& p);
	template <typename U> friend std::ostream& operator<<
		(std::ostream& , const Pile<U>& );
private:
	T * tab;
	int sommet;  // indice de l��l�ment au sommet
	int tailleMax;
	static const int MAX_PILE = 100;

};

//Template obligatoirement dans le .h 
template<typename U>
inline std::ostream & operator<<(std::ostream &, const Pile<U>&)
{
	// TODO: ins�rer une instruction return ici
}
