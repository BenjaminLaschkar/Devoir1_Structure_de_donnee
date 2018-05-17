#include "Piece.h"
#pragma once
class Utilities
{
public:
	Utilities();
	~Utilities();
	static int getRandValue(int inf, int sup);
	static void trierCarton(Piece *tableau_carton[5]);
};

