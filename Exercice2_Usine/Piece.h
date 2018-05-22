#pragma once

class Piece {
	private:
		bool estTraiter;
	public:
		Piece();
		~Piece();
		bool getEstTraiter();
		void setEstTraiter(bool newValue);
		virtual bool estTete() const = 0;
		virtual bool estAxe() const = 0;
		virtual bool estJupe() const = 0;
		virtual bool estPiston() const = 0;
};
