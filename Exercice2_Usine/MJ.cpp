#include "stdafx.h";
#include "MJ.h";
#include "Utilities.h";
#include "Windows.h";
#include <iostream>;
using namespace std;


MJ::MJ()
{
}


MJ::~MJ()
{
}

bool MJ::TraiterPiece(Tete & t)
{
	return false;
}

bool MJ::TraiterPiece(Axe & a)
{
	return false;
}

bool MJ::TraiterPiece(Jupe &j)
{
	cout << "Debut de traitement d'une Jupe. \n";
	if (j.getEstTraiter() == true) {
		//La piece est deja traitée
		return true;
	}
	//TODO: 1 - Temps d'attente (en seconde)
	double tpsAttente = 3;

	//TODO: 2- Calculer temps suplémentaire en vérifiant si un nombre aléatoire entre 0 et 10 est compri entre 0 et 25 (25% de chance de tomber en panne)
	int randValue = Utilities::getRandValue(1, 100);
	if (randValue >= 0 && randValue < 25) {
		cout << "Machine MJ en panne. \n";
		tpsAttente = tpsAttente + Utilities::getRandValue(5, 10);
	}
	Sleep(tpsAttente * 1000);

	//TODO: 3 -  Traitement de la pièce
	j.setEstTraiter(true);
	cout << "Fin de traitement d'une Jupe. \n";
	return true;
}

Piston * MJ::TraiterPiece(Tete & t, Jupe & j, Axe & a)
{
	return nullptr;
}
