#pragma once

#include "Axe.h";
#include "Jupe.h";
#include "Piston.h";
#include "Tete.h";

class Machine {
	public:
		Machine();
		~Machine();
	
		virtual bool TraiterPiece(Axe &a) = 0;
		virtual bool TraiterPiece(Jupe &j) = 0;
		virtual bool TraiterPiece(Tete &t) = 0;
		virtual Piston* TraiterPiece(Tete &t, Jupe &j,Axe &a) = 0;
};

