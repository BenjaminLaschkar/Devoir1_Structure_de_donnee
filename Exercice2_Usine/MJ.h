#pragma once
#include "Machine.h"
#include "Jupe.h"

class MJ :
	public Machine
{
public:
	MJ();
	~MJ();
	bool TraiterPiece(Tete &t) override;
	bool TraiterPiece(Axe &a) override;
	bool TraiterPiece(Jupe &j) override;
	Piston* TraiterPiece(Tete &t, Jupe &j, Axe &a) override;
	using Machine::TraiterPiece;
};

