#pragma once

class Piece {
	public:
		Piece();
		~Piece();
	
		bool getEstTraiter();
		void setEstTraiter(bool newValue);
	
		virtual bool estAxe() const = 0;
		virtual bool estJupe() const = 0;
		virtual bool estTete() const = 0;
		virtual bool estPiston() const = 0;

	private:
		bool estTraiter;
};

