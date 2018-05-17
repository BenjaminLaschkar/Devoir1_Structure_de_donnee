#pragma once
#include "Piece.h"
#include "Tete.h"
#include "Jupe.h"
#include "Axe.h"

class Piston :
	public Piece {
		private:
			Tete tete;
			Jupe jupe;
			Axe axe;
		public:
			Piston();
			~Piston();
	};

