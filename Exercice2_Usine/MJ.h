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
		Piston* TraiterPiece(Tete &t, Jupe &j, Axe &a) override;
		using Machine::TraiterPiece;
};

