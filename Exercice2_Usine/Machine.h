#include "Axe.h";
#include "Jupe.h";
#include "Tete.h";
#include "Piston.h";
#pragma once

class Machine {
	public:
		Machine();
		~Machine();

		virtual bool TraiterPiece(Axe &a) = 0;
		virtual bool TraiterPiece(Jupe &j) = 0;
		virtual bool TraiterPiece(Tete &t) = 0;
		virtual Piston* TraiterPiece(Tete &t, Jupe &j,Axe &a) = 0;
};

