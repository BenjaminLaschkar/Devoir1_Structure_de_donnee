#pragma once
#include "Machine.h"
#include "Axe.h"

class MA :
	public Machine
{
public:
	MA();
	~MA();
	bool TraiterPiece(Tete &t) override;
	bool TraiterPiece(Axe &a) override;
	bool TraiterPiece(Jupe &j) override;
	Piston* TraiterPiece(Tete &t, Jupe &j, Axe &a) override;
	using Machine::TraiterPiece;
};

