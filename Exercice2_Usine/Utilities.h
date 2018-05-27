#include "Piece.h";
#include "File.h";
#include <vector>;
#pragma once

class Utilities {
public:
	Utilities();
	~Utilities();

	static int getRandValue(int inf, int sup);
	static vector<Piece*> genererCarton(int nbPiecesMax);
	static void supprimerCarton(vector<Piece*> &carton);
	static void trieCarton(vector<Piece*> &carton, File<Axe> &fAxe, File<Jupe> &fJupe, File<Tete> &fTete);
};


