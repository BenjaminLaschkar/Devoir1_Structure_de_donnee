#pragma once
#include "Piece.h"

class Axe :
	public Piece {
		public:
			Axe();
			~Axe();
			virtual bool estTete() const;
			virtual bool estAxe() const;
			virtual bool estJupe() const;
			virtual bool estPiston() const;
};

