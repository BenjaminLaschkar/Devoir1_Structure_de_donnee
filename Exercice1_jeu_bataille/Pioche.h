#include "stdafx.h"
#include "Carte.h"
#include "Pile.h"
#include <time.h>
#include <iostream>
#include <tuple>
#include "Pile.cpp" //Afin d'éviter le LNK2019 il faut compiler les librairie utilisant un template : https://stackoverflow.com/questions/3705740/c-lnk2019-error-unresolved-external-symbol-template-classs-constructor-and
#define MAX_CARTE 100
using namespace std;

class Pioche
{
public:
	Pioche(int nombre_de_carte_par_joueur);
	~Pioche();
	Pile<Carte> pioche ;
	tuple<Pile<Carte>, Pile<Carte>> Distribuer();
	int nombre_de_carte_par_joueur;
};

