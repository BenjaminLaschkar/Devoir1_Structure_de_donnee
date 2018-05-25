// Exercice2_Usine.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h";
#include "Axe.h";
#include "File.cpp";
#include "File.h";
#include "MA.h";
#include "Machine.h";
#include "MJ.h";
#include "MP.h";
#include "MT.h"; 
#include "Jupe.h";
#include "Piece.h"
#include "Tete.h";
#include "time.h";
#include "Utilities.h";
#include <iostream>;
#include <vector>

using namespace std;

int main() {
	srand(time(NULL));
	MA ma = MA();
	MJ mj = MJ();
	MT mt = MT();
	MP mp = MP();
	int nbPiecesMax = 300;
	int nbPistonAFabriquer = 100;

	File<Axe>  fAxe;
	File<Jupe> fJupe;
	File<Tete> fTete;
	File<Piston> fPiston;
	File<Axe>  fAxeTraite;
	File<Jupe> fJupeTraite;
	File<Tete> fTeteTraite;

	vector<Piece*> carton;

	carton = Utilities::genererCarton(carton, nbPiecesMax);
	
	Utilities::trieCarton(carton);
	Utilities::supprimerCarton(carton);

	for (int i = 1; i <= 10; i++) {
		Axe a  = Axe();
	    Jupe j = Jupe();
		Tete t = Tete();

		fAxe.enfiler(a);
		fJupe.enfiler(j);
		fTete.enfiler(t);
	}

	cout << " --- USINAGE DES PIECES ---";
	
	while(fPiston.taille()< nbPistonAFabriquer) {
		Axe axeCourante;
		Jupe jupeCourante;
		Tete teteCourante;
		if (((fAxe.estVide() && fAxeTraite.estVide()) || (fJupe.estVide() && fJupeTraite.estVide()) || fTete.estVide() && fTeteTraite.estVide()) ) {
			cout << "Generer des cartons. \n";
		}

		if (fAxeTraite.estVide()) {
			if (!fAxe.estVide()) {
				axeCourante = fAxe.defiler();
				ma.TraiterPiece(axeCourante);
			}
		}
		else
			axeCourante = fAxeTraite.defiler();

		if (fJupeTraite.estVide()) {
			if (!fJupe.estVide()) {
				jupeCourante = fJupe.defiler();
				mj.TraiterPiece(jupeCourante);
			}
		}
		else 
			jupeCourante = fJupeTraite.defiler();
		
		if (fTeteTraite.estVide()) {
			if (!fTete.estVide()) {
				teteCourante = fTete.defiler();
				mt.TraiterPiece(teteCourante);
			}
		}
		else
			teteCourante = fTeteTraite.defiler();
		
		//Si toutes les pièces n'ont pas été traitées
		if (!axeCourante.getEstTraiter() || !jupeCourante.getEstTraiter() || !teteCourante.getEstTraiter()) {
			if (axeCourante.getEstTraiter())  { fAxeTraite.enfiler(axeCourante);   }
			if (jupeCourante.getEstTraiter()) { fJupeTraite.enfiler(jupeCourante); }
			if (teteCourante.getEstTraiter()) { fTeteTraite.enfiler(teteCourante); }
		}
		else {
			//Sinon on fabrique le piston et on l'enfile
			Piston p = *mp.TraiterPiece(teteCourante, jupeCourante, axeCourante);
			if (p.getEstTraiter()) { fPiston.enfiler(p); }
		}
		cout << "------------------------------------------------\n";
	}

	getchar();
	return 0;
}

