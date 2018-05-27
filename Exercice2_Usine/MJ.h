#include "Jupe.h"
#include "Machine.h"
#pragma once

class MJ : public Machine {
	public:
		MJ();
		~MJ();

		bool TraiterPiece(Axe &a) override;
		bool TraiterPiece(Jupe &j) override;
		bool TraiterPiece(Tete &t) override;
		Piston* TraiterPiece(Axe &a, Jupe &j, Tete &t) override;
		using Machine::TraiterPiece;
};

