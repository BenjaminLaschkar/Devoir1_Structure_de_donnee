#pragma once

#include "Piece.h"

class Tete : public Piece {
	public:
		Tete();
		~Tete();
	
		virtual bool estAxe() const;
		virtual bool estJupe() const;
		virtual bool estTete() const;
		virtual bool estPiston() const;
};

