// Exercice2_Usine.cpp�: d�finit le point d'entr�e pour l'application console.
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
#include <vector>
using namespace std;

int main() {
	srand(time(NULL));
	MT mt = MT();
	MA ma = MA();
	MJ mj = MJ();
	MP mp = MP();
	File<Axe>  fAxe (100);
	File<Jupe> fJupe(100);
	File<Tete> fTete(100);
	File<Piston> fPistonCree (100);
	File<Axe>  fAxeTraite (100);
	File<Jupe> fJupeTraite(100);
	File<Tete> fTeteTraite(100);
	int nbPistonAFabriquer = 100;
	int nbPiecesMax = 300;

	vector<Piece*> carton;

	// Premier carton
	carton = Utilities::genererCarton(nbPiecesMax);
	Utilities::trieCarton(carton, fAxe, fJupe, fTete);
	Utilities::supprimerCarton(carton);
	
	cout << "\n --- USINAGE DES PIECES ---\n\n";
	while (fPistonCree.taille() < nbPistonAFabriquer) {
		Tete teteCourante;
		Jupe jupeCourante;
		Axe axeCourante;

		if (FilesPasPretes(fTete, fTeteTraite, fJupe, fJupeTraite, fAxe, fAxeTraite) == true) {
			cout << "En attente de cartons... \n";
			carton = Utilities::genererCarton(nbPiecesMax);
			Utilities::trieCarton(carton, fAxe, fJupe, fTete);
			Utilities::supprimerCarton(carton);
			continue;
		}
		
		RecuperationAxe(fAxeTraite, fAxe, axeCourante, ma);
		RecuperationJupe(fJupeTraite, fJupe, jupeCourante, mj);
		RecuperationTete(fTeteTraite, fTete, teteCourante, mt);
		Piston p = *mp.TraiterPiece(fAxeTraite.defiler(), fJupeTraite.defiler(), fTeteTraite.defiler());
		if (p.getEstTraiter()) { fPistonCree.enfiler(p); }
		cout << fPistonCree.taille();

		cout << "------------------------------------------------\n";
	}
	
	getchar();
	return 0;
}

/*void AttributionFiles(File<Axe> &fAxe, File<Jupe> &fJupe, File<Tete> &fTete) {
	for (int i = 1; i <= 10; i++) {
		Axe a = Axe();
		Jupe j = Jupe();
		Tete t = Tete();

		fAxe.enfiler(a);
		fJupe.enfiler(j);
		fTete.enfiler(t);
	}
}*/
void RecuperationAxe(File<Axe> &fAxeTraite, File<Axe> &fAxe, Axe &axeCourante, MA &ma) {
	if (fAxeTraite.estVide()) {
		if (!fAxe.estVide()) {
			axeCourante = fAxe.defiler();
			ma.TraiterPiece(axeCourante);
			fAxeTraite.enfiler(axeCourante);
			}
	}
}
void RecuperationJupe(File<Jupe> &fJupeTraite, File<Jupe> &fJupe, Jupe &jupeCourante, MJ &mj) {
	if (fJupeTraite.estVide()) {
		if (!fJupe.estVide()) {
			jupeCourante = fJupe.defiler();
			mj.TraiterPiece(jupeCourante);
			fJupeTraite.enfiler(jupeCourante);
		}
	}
}
void RecuperationTete(File<Tete> &fTeteTraite, File<Tete> &fTete, Tete &teteCourante, MT &mt) {
	if (fTeteTraite.estVide()) {
		if (!fTete.estVide()) {
			teteCourante = fTete.defiler();
			mt.TraiterPiece(teteCourante);
			fTeteTraite.enfiler(teteCourante);
		}
	}
}
bool FilesPasPretes(File<Tete> &fTete, File<Tete> &fTeteTraite, File<Jupe> &fJupe, File<Jupe> &fJupeTraite, File<Axe> &fAxe, File<Axe> &fAxeTraite) {
	if ((fAxe.estVide() && fAxeTraite.estVide()) || (fJupe.estVide() && fJupeTraite.estVide()) || (fTete.estVide() && fTeteTraite.estVide())) { return true; }
	return false;
}

