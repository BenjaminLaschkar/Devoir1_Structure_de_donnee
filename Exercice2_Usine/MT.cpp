#include "stdafx.h"
#include "MT.h"
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;
MT::MT()
{
}

MT::~MT()
{
}

bool MT::TraiterPiece(Tete &t)
{
	cout << "Debut de traitement d'une t�te \n";
	if (t.getEstTraiter() == true) {
		//La piece est deja trait�e
		return true;
	}

	//TODO: 1 - Temps d'attente (en seconde)
	double tpsAttente = 2;

	//TODO: 2- Calculer temps supl�mentaire en v�rifiant si un nombre al�atoire entre 0 et 10 est compri entre 0 et 25 (25% de chance de tomber en panne)
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "Machine MT en panne \n";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	 }
	Sleep(tpsAttente*1000);

	//3 - Traitement de la pi�ce
	t.setEstTraiter(true);
	

	//TODO: 3 - 
	cout << "Fin de traitement d'une t�te";
	return true;
}

bool MT::TraiterPiece(Axe & a)
{
	return false;
}

bool MT::TraiterPiece(Jupe & j)
{
	return false;
}

Piston * MT::TraiterPiece(Tete & t, Jupe & j, Axe & a)
{
	return nullptr;
}

