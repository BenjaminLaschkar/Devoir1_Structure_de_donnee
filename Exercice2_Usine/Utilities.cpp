#include "stdafx.h"
#include "Utilities.h"
#include "stdlib.h";
#include "Time.h";
#include "Math.h";
#include "Tete.h";
#include "Axe.h";
#include "Jupe.h";
#include <typeinfo>; // permet de comparer deux types d'objet
#include <iostream>;
#include <vector>

using namespace std;
Utilities::Utilities()
{
}


Utilities::~Utilities()
{
}

int Utilities::getRandValue(int inf, int sup) {
	int randValue = (rand() % sup) + inf;
	return randValue;
}

