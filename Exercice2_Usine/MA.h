#include "Axe.h"
#include "Machine.h"
#pragma once

class MA : public Machine {
	public:
		MA();
		~MA();

		bool TraiterPiece(Axe &a) override;
		bool TraiterPiece(Jupe &j) override;
		bool TraiterPiece(Tete &t) override;
		Piston* TraiterPiece(Axe &a, Jupe &j, Tete &t) override;
		using Machine::TraiterPiece;
};

