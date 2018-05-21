#pragma once
#include "Machine.h"
#include "Tete.h"

class MT :
	public Machine
{
public:
	MT();
	~MT();
	bool TraiterPiece(Tete &t) override; 
	bool TraiterPiece(Axe &a) override;
	bool TraiterPiece(Jupe &j) override;
	Piston* TraiterPiece(Tete &t, Jupe &j, Axe &a) override;
	using Machine::TraiterPiece;
};

