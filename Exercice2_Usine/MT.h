#pragma once
#include "Machine.h"
#include "Tete.h"
class MT :
	public Machine
{
public:
	MT();
	~MT();
	bool TraiterPiece(Tete t) override; 
	using Machine::TraiterPiece;
};

