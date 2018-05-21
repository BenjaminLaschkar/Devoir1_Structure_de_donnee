#include "stdafx.h"
#include "MA.h"
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;


MA::MA()
{
}
MA::~MA()
{
}
bool MA::TraiterPiece(Axe &a)
{
	cout << "Debut de traitement d'un Axe \n";
	if (a.getEstTraiter() == true) {
		//La piece est deja traitée
		return true;
	}
	//TODO: 1 - Temps d'attente (en seconde)
	double tpsAttente = 2.5;

	//TODO: 2- Calculer temps suplémentaire en vérifiant si un nombre aléatoire entre 0 et 10 est compri entre 0 et 25 (25% de chance de tomber en panne)
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "Machine MA en panne \n";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	//3 - Traitement de la pièce
	a.setEstTraiter(true);
	//TODO: 3 - 
	cout << "Fin de traitement d'une tête";
	return true;
}
bool MA::TraiterPiece(Tete & t)
{
	return false;
}
bool MA::TraiterPiece(Jupe & j)
{
	return false;
}
Piston * MA::TraiterPiece(Tete & t, Jupe & j, Axe & a)
{
	return nullptr;
}
