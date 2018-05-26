#pragma once

#include "Axe.h"
#include "Machine.h"

class MA : public Machine {
	public:
		MA();
		~MA();
	
		bool TraiterPiece(Axe &a) override;
		bool TraiterPiece(Jupe &j) override;
		bool TraiterPiece(Tete &t) override;
		Piston* TraiterPiece(Tete &t, Jupe &j, Axe &a) override;
		using Machine::TraiterPiece;
};

