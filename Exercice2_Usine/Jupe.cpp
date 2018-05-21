#include "stdafx.h"
#include "Jupe.h"

Jupe::Jupe() {
}

Jupe::~Jupe() {
}

bool Jupe::estTete() const { return false; }
bool Jupe::estAxe()  const { return false; }
bool Jupe::estJupe() const { return true; }
