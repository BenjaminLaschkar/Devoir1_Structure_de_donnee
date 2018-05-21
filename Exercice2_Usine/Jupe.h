#pragma once
#include "Piece.h"

class Jupe :
	public Piece {
		public:
			Jupe();
			~Jupe();
			virtual bool estTete() const;
			virtual bool estAxe() const;
			virtual bool estJupe() const;
			virtual bool estPiston() const;
	};

