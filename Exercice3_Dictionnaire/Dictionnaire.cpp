#include "Dictionnaire.h"


Dictionnaire & Dictionnaire::ajouterMot(std::string const & mot)
{
}

bool Dictionnaire::chercherMot(std::string const & mot) const
{
	if(mot.length == 1)
		return mot[0] == lettre && endOfWord;
	else
	{
		if (suite == nullptr && alternative == nullptr)
			return false;

		else if (mot[0] == lettre)
		{
			if (suite == nullptr)
				return false;
			else
				suite->chercherMot(mot.substr(1, mot.length - 1));
		}

		else if (alternative != nullptr)
			return alternative->chercherMot(mot);
		else
			return false;
	}

}
