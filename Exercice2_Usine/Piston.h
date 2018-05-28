
#include "Axe.h"
#include "Jupe.h"
#include "Piece.h"
#include "Tete.h"
#pragma once

class Piston : public Piece {
	public:
		Piston();
		~Piston();
	
		virtual bool estAxe() const;
		virtual bool estJupe() const;
		virtual bool estTete() const;
		virtual bool estPiston() const;
	
	private:
		Axe axe;
		Jupe jupe;
		Tete tete;
};

