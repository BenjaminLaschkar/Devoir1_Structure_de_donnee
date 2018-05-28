#include "Piece.h"
#pragma once

class Axe : public Piece {
	public:
		Axe();
		~Axe();
	
		virtual bool estAxe() const;
		virtual bool estJupe() const;
		virtual bool estTete() const;
		virtual bool estPiston() const;
};

