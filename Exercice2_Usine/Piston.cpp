#include "stdafx.h"
#include "Piston.h"


Piston::Piston()
{

}


Piston::~Piston()
{
}

bool Piston::estTete() const { return false; }
bool Piston::estAxe()  const { return false; }
bool Piston::estJupe() const { return false; }
bool Piston::estPiston() const { return true; }