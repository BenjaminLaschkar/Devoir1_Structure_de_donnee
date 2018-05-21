#include "stdafx.h"
#include "Axe.h"

Axe::Axe() {
}

Axe::~Axe() {
}

bool Axe::estTete() const { return false; }
bool Axe::estAxe()  const { return true; }
bool Axe::estJupe() const { return false; }
bool Axe::estPiston() const { return false; }
