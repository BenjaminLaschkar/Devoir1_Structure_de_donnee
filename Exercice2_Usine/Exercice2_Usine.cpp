// Exercice2_Usine.cpp�: d�finit le point d'entr�e pour l'application console.
//

#include "stdafx.h";
#include <iostream>;
#include <vector>

#include "Utilities.h";
#include "Piece.h"
#include "Tete.h";
#include "Axe.h";
#include "Jupe.h";
#include "Machine.h";
#include "MT.h";
#include "File.h";
#include "File.cpp"
#include "time.h"

using namespace std;

int main() {
	srand(time(NULL));
	int nbPiecesMax = 5;

	vector<Piece*> carton;

	//Utilities::genererCarton(carton, nbPiecesMax);

	/* WORKIKNG */
	
		// Ajout pi�ce
		carton.push_back(new Axe());
		carton.push_back(new Jupe());
		carton.push_back(new Axe());
		carton.push_back(new Tete());
		carton.push_back(new Axe());
	
		for (int i = 0; i<carton.size(); ++i) {
			
			cout << carton[i];
			cout << "\n";
			
			if (carton[i]->estTete() == true) { cout << "Tete\n"; }
			if (carton[i]->estAxe()  == true) { cout << "Axe\n";  }
			if (carton[i]->estJupe() == true) { cout << "Jupe\n"; }
		}
	
		// Supprime le pr�c�dent carton
		for (int i = 0; i<carton.size(); ++i) {
			delete carton[i];  //On lib�re la i-�me case m�moire allou�e
			carton[i] = 0;  //On met le pointeur � 0 pour �viter les soucis
		}
	

	// Pause pour voir le resultat
	getchar();

	return 0;
}

