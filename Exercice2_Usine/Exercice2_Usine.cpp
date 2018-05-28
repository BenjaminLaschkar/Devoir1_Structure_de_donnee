// Exercice2_Usine.cpp : définit le point d'entrée pour l'application console.
//
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
#include "Exercice2_Usine.h";
#include <iostream>;
#include <vector>;
#include <string>

using namespace std;

int main() {
	//Heure de debut
	time_t now;
	time(&now);

	MT mt = MT();
	MA ma = MA();
	MJ mj = MJ();
	MP mp = MP();
	srand(time(NULL));
	vector<Piece*> carton;
	int nbPistonAFabriquer = 100;
	int nbPiecesMax = 3 * nbPistonAFabriquer;

	File<Axe> fAxe(nbPistonAFabriquer);
	File<Jupe> fJupe (nbPistonAFabriquer);
	File<Tete> fTete(nbPistonAFabriquer);
	File<Piston> fPistonCree (nbPistonAFabriquer);
	File<Axe> fAxeTraite(nbPistonAFabriquer);
	File<Jupe> fJupeTraite (nbPistonAFabriquer);
	File<Tete> fTeteTraite(nbPistonAFabriquer);

	

	cout << "\n***************************************************************\n" << endl;
	cout << "**                 LANCEMENT DE LA SIMULATION                **\n" << endl;
	cout << "**                 --------------------------                **\n" << endl;
	cout << "**              CHAINE DE MONTAGE DE " << nbPistonAFabriquer << " PISTONS             **\n" << endl;
	cout << "***************************************************************" << endl;

	// Premier Carton
	carton = Utilities::genererCarton(nbPiecesMax);
	Utilities::trieCarton(carton, fAxe, fJupe, fTete);
	Utilities::supprimerCarton(carton);

	while (fPistonCree.taille() < nbPistonAFabriquer) {
		//Heure de debut de la boucle
		time_t heureBoucle;
		time(&heureBoucle);

		Tete teteCourante = Tete();
		Jupe jupeCourante = Jupe();
		Axe axeCourante = Axe();


		if (FilesPasPretes(fTete, fTeteTraite, fJupe, fJupeTraite, fAxe, fAxeTraite) == true) {
			cout << "En attente de cartons... " << endl;
			carton = Utilities::genererCarton(nbPiecesMax);
			Utilities::trieCarton(carton, fAxe, fJupe, fTete);
			Utilities::supprimerCarton(carton);
		}

		// Recuperation des pieces usinee
		RecuperationTete(fTeteTraite, fTete, teteCourante, mt);
		RecuperationAxe(fAxeTraite, fAxe, axeCourante, ma);
		RecuperationJupe(fJupeTraite, fJupe, jupeCourante, mj);

		// Assemblage
		if (!teteCourante.getEstTraiter() || !jupeCourante.getEstTraiter() || !axeCourante.getEstTraiter()) {
			if (axeCourante.getEstTraiter()) { fAxeTraite.enfiler(axeCourante); }
			if (jupeCourante.getEstTraiter()) { fJupeTraite.enfiler(jupeCourante); }
			if (teteCourante.getEstTraiter()) { fTeteTraite.enfiler(teteCourante); }
		} else {
			//Sinon on fabrique le piston et on l'enfile
			Piston p = *mp.TraiterPiece(teteCourante, jupeCourante, axeCourante);

			if (p.getEstTraiter()) {
				fPistonCree.enfiler(p);
				cout << "Piston fabrique en : " << Utilities::getDifferenceHour(heureBoucle) << " secondes." << endl;
				cout << "Nombre de pistons: " << fPistonCree.taille() << " (Reste: " << nbPistonAFabriquer - fPistonCree.taille() << " pistons)." << endl;
			}
		}
		cout << "------------------------------------------------" << endl;
	}
	cout << nbPistonAFabriquer << " Pistons fabriques en : " << Utilities::getDifferenceHour(now) << " secondes. Soit : " << Utilities::conversionTemps(now) << endl;
	getchar();
	return 0;
}

void RecuperationJupe(File<Jupe> &fJupeTraite, File<Jupe> &fJupe, Jupe &jupeCourante, MJ &mj) {
	if (fJupeTraite.estVide()) {
		cout << "Aucune jupe usinee" << endl;
		if (!fJupe.estVide()) {
			cout << "Usinage d'une nouvelle jupe" << endl;
			jupeCourante = fJupe.defiler();
			mj.TraiterPiece(jupeCourante);
		}
	} else {
		cout << "Jupe usinee disponible !" << endl;
		jupeCourante = fJupeTraite.defiler();
	}
}

void RecuperationAxe(File<Axe> &fAxeTraite, File<Axe> &fAxe, Axe &axeCourante, MA &ma) {
	if (fAxeTraite.estVide()) {
		cout << "Aucun axe usinee" << endl;
		if (!fAxe.estVide()) {
			cout << "Usinage d'un nouvel axe" << endl;
			axeCourante = fAxe.defiler();
			ma.TraiterPiece(axeCourante);
		}
	} else {
		cout << "Axe usinee disponible !" << endl;
		axeCourante = fAxeTraite.defiler();
	}
}

void RecuperationTete(File<Tete> &fTeteTraite, File<Tete> &fTete, Tete &teteCourante, MT &mt) {
	if (fTeteTraite.estVide()) {
		cout << "Aucune tete usinee" << endl;
		if (!fTete.estVide()) {
			cout << "Usinage d'une nouvelle tete" << endl;
			teteCourante = fTete.defiler();
			mt.TraiterPiece(teteCourante);
		}
	} else {
	    cout << "Tete usinee disponible !" << endl;
		teteCourante = fTeteTraite.defiler();
	}
}

bool FilesPasPretes(File<Tete> &fTete, File<Tete> &fTeteTraite, File<Jupe> &fJupe, File<Jupe> &fJupeTraite, File<Axe> &fAxe, File<Axe> &fAxeTraite) {
	if ((fTete.estVide() && fTeteTraite.estVide()) || (fJupe.estVide() && fJupeTraite.estVide()) || (fAxe.estVide() && fAxeTraite.estVide())) { return true; }
	return false;
}

void AttributionFiles(File<Tete> &fTete, File<Jupe> &fJupe, File<Axe> &fAxe) {
	for (int i = 1; i <= 10; i++) {
		Axe a = Axe();
		Jupe j = Jupe();
		Tete t = Tete();

		fJupe.enfiler(j);
		fAxe.enfiler(a);
		fTete.enfiler(t);
	}
}


