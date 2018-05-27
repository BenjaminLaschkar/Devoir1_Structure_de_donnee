#include "stdafx.h"
#include "Tete.h"

Tete::Tete() {
	setEstTraiter(false);
}
Tete::~Tete() {}

bool Tete::estAxe()  const { return false; }
bool Tete::estJupe() const { return false; }
bool Tete::estTete() const { return true; }
bool Tete::estPiston() const { return false; }
