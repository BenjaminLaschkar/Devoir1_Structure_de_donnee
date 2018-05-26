#pragma once

#include "Piece.h";
#include <vector>;

using namespace std;

class Utilities {
	public:
		Utilities();
		~Utilities();
		
		static int getRandValue(int inf, int sup);
		static vector<Piece*> genererCarton(vector<Piece*> carton, int nbPiecesMax);
		static void trieCarton(vector<Piece*> carton);
		static void supprimerCarton(vector<Piece*> carton);
};


