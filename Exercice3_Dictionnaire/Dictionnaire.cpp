#include "Dictionnaire.h"


Dictionnaire & Dictionnaire::ajouterMot(std::string const & mot)
{
	//TODO : Traiter le cas ou le dictionnaire est complètement vide
	if (mot.length() == 1)
	{
		if (mot[0] == lettre)
			endOfWord = true;

		else if (alternative == nullptr)
		{
			alternative = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			alternative->lettre = mot[0];
			alternative->endOfWord = true;
		}

		else if (alternative->lettre > mot[0])
		{
			std::unique_ptr<Dictionnaire> nouveauNoeud = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			nouveauNoeud->lettre = mot[0];
			nouveauNoeud-> //TODO
		}

		else
			alternative->ajouterMot(mot);
	}
	else
	{
		//TODO
	}
}

bool Dictionnaire::chercherMot(std::string const & mot) const
{
	if(mot.length() == 1)
		return (alternative != nullptr) ? mot[0] == lettre && endOfWord || alternative->chercherMot(mot) : mot[0] == lettre && endOfWord;
	else
	{
		if (mot[0] == lettre && suite != nullptr)
			return suite->chercherMot(mot.substr(1, mot.length - 1));

		else if (mot[0] != lettre && alternative != nullptr)
			return alternative->chercherMot(mot);

		else
			return false;
	}

}

bool Dictionnaire::estVide() const
{
	return lettre == 0;
}
