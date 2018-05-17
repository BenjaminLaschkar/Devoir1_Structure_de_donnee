#pragma once
#include "Machine.h"
#include "Tete.h"
#include "Jupe.h"
#include "Axe.h"
class MP :
	public Machine
{
public:
	MP();
	~MP();
	Piston* TraiterPiece(Tete t, Jupe j, Axe a);
};

