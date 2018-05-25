#include "stdafx.h"
#include "Jupe.h"

Jupe::Jupe() {
	setEstTraiter(false);
}

Jupe::~Jupe() {}

bool Jupe::estAxe()  const { return false; }
bool Jupe::estJupe() const { return true; }
bool Jupe::estTete() const { return false; }
bool Jupe::estPiston() const { return false; }
