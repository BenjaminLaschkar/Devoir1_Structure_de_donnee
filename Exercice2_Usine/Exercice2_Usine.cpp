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
#include <vector>

using namespace std;

int main() {
	// Création des instances 
	//srand(time(NULL));
	MT mt = MT();
	MA ma = MA();
	MJ mj = MJ();
	MP mp = MP();
	File<Tete> fTete (100);
	File<Jupe> fJupe (100);
	File<Axe> fAxe (100);
	File<Piston> fPistonCree (100);// = File<Piston>();
	File<Tete>fTeteTraite (100);
	File<Jupe> fJupeTraite (100);
	File<Axe> fAxeTraite (100);
	int nbPistonAFabriquer = 100;
	int nbPiecesMax = 300;

	vector<Piece*> carton;
	carton = Utilities::genererCarton(nbPiecesMax);
	Utilities::trieCarton(carton, fAxe, fJupe, fTete);
	Utilities::supprimerCarton(carton);
	
	//AttributionFiles(fTete, fJupe, fAxe);
	
	cout << " --- USINAGE DES PIECES ---";
	// tant que les pistons créés sont moins nombreux que le nombre a fabriquer
	while(fPistonCree.taille()< nbPistonAFabriquer) {
		Tete teteCourante;
		Jupe jupeCourante;
		Axe axeCourante;

		// si une des files elements traités et non traites sont vides
		// on demande un nouveau carton
		if (FilesPasPretes(fTete, fTeteTraite, fJupe, fJupeTraite, fAxe, fAxeTraite) == true) {
			cout << "En attente de cartons... \n";
			// appeler la fonction qui genere et trie de nouveaux cartons
			carton = Utilities::genererCarton(nbPiecesMax);
			Utilities::trieCarton(carton, fAxe, fJupe, fTete);
			continue;
		}

		// sinon on commence a fabriquer les pistons
			// on recupere une tete usinée
				// on regarde dans la file des tetes usinne sil y en a de dispo
				// sinon on prend une dans la file de depart, on l úsine et on la mets dans la file des traitees
				RecuperationTete(fTeteTraite, fTete, teteCourante, mt);

			// on recupere un axe usiné
				RecuperationAxe(fAxeTraite, fAxe, axeCourante, ma);

			// on recupere une juppe usinée
				RecuperationJupe(fJupeTraite, fJupe, jupeCourante, mj);

			// on assemble le tout
			// on ajoute le piston a la file des pistons créés
			Piston p = *mp.TraiterPiece(teteCourante, jupeCourante, axeCourante);
			if (p.getEstTraiter()) {
				fPistonCree.enfiler(p);
			}



		


		//Si toutes les pièces n'ont pas été traitées
		//if (!teteCourante.getEstTraiter() || !jupeCourante.getEstTraiter() || !axeCourante.getEstTraiter()) {
		//	if (teteCourante.getEstTraiter())
		//		fTeteTraite.enfiler(teteCourante);

		//	if (jupeCourante.getEstTraiter())
		//		fJupeTraite.enfiler(jupeCourante);

		//	if (axeCourante.getEstTraiter())
		//		fAxeTraite.enfiler(axeCourante);
		//}
		//else {
		//	//Sinon on fabrique le piston et on l'enfile
		//	Piston p = *mp.TraiterPiece(teteCourante, jupeCourante, axeCourante);
		//	if (p.getEstTraiter()) {
		//		fPistonCree.enfiler(p);

		//	}
		//}
		cout << "------------------------------------------------\n";
		
	}



	getchar();
	return 0;
}

void RecuperationJupe(File<Jupe> &fJupeTraite, File<Jupe> &fJupe, Jupe &jupeCourante, MJ &mj)
{
	if (fJupeTraite.estVide()) {
		if (!fJupe.estVide()) {
			jupeCourante = fJupe.defiler();
			mj.TraiterPiece(jupeCourante);
			fJupeTraite.enfiler(jupeCourante);
		}

	}
	else {
		jupeCourante = fJupeTraite.defiler();
	}
}

void RecuperationAxe(File<Axe> &fAxeTraite, File<Axe> &fAxe, Axe &axeCourante, MA &ma)
{
	if (fAxeTraite.estVide()) {
		if (!fAxe.estVide()) {
			axeCourante = fAxe.defiler();
			ma.TraiterPiece(axeCourante);
			fAxeTraite.enfiler(axeCourante);

		}

	}
	else {
		axeCourante = fAxeTraite.defiler();
	}
}

void RecuperationTete(File<Tete> &fTeteTraite, File<Tete> &fTete, Tete &teteCourante, MT &mt)
{
	if (fTeteTraite.estVide()) {
		if (!fTete.estVide()) {
			teteCourante = fTete.defiler();
			mt.TraiterPiece(teteCourante);
			fTeteTraite.enfiler(teteCourante);
		}
	}
	else {
		teteCourante = fTeteTraite.defiler();
	}
}

bool FilesPasPretes(File<Tete> &fTete, File<Tete> &fTeteTraite, File<Jupe> &fJupe, File<Jupe> &fJupeTraite, File<Axe> &fAxe, File<Axe> &fAxeTraite)
{
	if ((fTete.estVide() && fTeteTraite.estVide()) ||
		(fJupe.estVide() && fJupeTraite.estVide()) ||
		(fAxe.estVide() && fAxeTraite.estVide())) {
		return true;
	}
	return false;
}

void AttributionFiles(File<Tete> &fTete, File<Jupe> &fJupe, File<Axe> &fAxe)
{
	for (int i = 1; i <= 10; i++) {
		Tete t = Tete();
		Axe a = Axe();
		Jupe j = Jupe();
		fTete.enfiler(t);
		fJupe.enfiler(j);
		fAxe.enfiler(a);
	}
}


