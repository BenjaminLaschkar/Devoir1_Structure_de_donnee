#pragma once

#include "Machine.h"

class MP : public Machine {
	public:
		MP();
		~MP();

		bool TraiterPiece(Axe &a) override;
		bool TraiterPiece(Jupe &j) override;
		bool TraiterPiece(Tete &t) override;
		Piston* TraiterPiece(Tete &t, Jupe &j, Axe &a) override;
		using Machine::TraiterPiece;
};

