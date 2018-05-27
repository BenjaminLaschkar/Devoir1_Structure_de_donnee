#include "Machine.h"
#pragma once

class MP : public Machine {
	public:
		MP();
		~MP();

		bool TraiterPiece(Axe &a) override;
		bool TraiterPiece(Jupe &j) override;
		bool TraiterPiece(Tete &t) override;
		Piston* TraiterPiece(Axe &a, Jupe &j, Tete &t) override;
		using Machine::TraiterPiece;
};

