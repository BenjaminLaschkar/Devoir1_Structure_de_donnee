#include "Machine.h"
#include "Tete.h"
#pragma once

class MT : public Machine {
	public:
		MT();
		~MT();

		bool TraiterPiece(Axe &a) override;
		bool TraiterPiece(Jupe &j) override;
		bool TraiterPiece(Tete &t) override;
		Piston* TraiterPiece(Axe &a, Jupe &j, Tete &t) override;
		using Machine::TraiterPiece;
};

