#include "Dictionnaire.h"


Dictionnaire & Dictionnaire::ajouterMot(std::string const & mot)
{
	if (mot.length() == 1)
	{
		if (estVide())
		{
			lettre = mot[0];
			endOfWord = true;
		}

		else if (mot[0] == lettre)
			endOfWord = true; 

		//Il manque le cas ou lettre > mot[0] pour conserver l'ordre lexico

		else if (alternative == nullptr)
		{
			alternative = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			alternative->ajouterMot(mot);
		}

		else if (alternative->lettre > mot[0])
		{
			std::unique_ptr<Dictionnaire> nouveauNoeud = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			nouveauNoeud->ajouterMot(mot);
			nouveauNoeud->alternative = std::move(alternative);
			alternative = std::move(nouveauNoeud);
		}

		else
			alternative->ajouterMot(mot);

	}
	else if(mot.length() > 1)
	{
		if (estVide())
		{
			lettre = mot[0];
			suite = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			suite->ajouterMot(mot.substr(1, mot.length() - 1));
		}
		else if (mot[0] == lettre)
			suite->ajouterMot(mot.substr(1, mot.length() - 1));

		//Il manque le cas ou lettre > mot[0] pour conserver l'ordre lexico

		else if (alternative == nullptr)
		{
			alternative = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			alternative->ajouterMot(mot);
		}

		else if (alternative->lettre > mot[0])
		{
			auto nouveauNoeud = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			nouveauNoeud->ajouterMot(mot);
			nouveauNoeud->alternative = std::move(alternative);
			alternative = std::move(nouveauNoeud);
		}
		else
			alternative->ajouterMot(mot);
	}

	return *this;
}

bool Dictionnaire::chercherMot(std::string const & mot) const
{
	if (estVide() || mot.length() < 1)
		return false;
	else if(mot.length() == 1)
		return (alternative != nullptr) ? mot[0] == lettre && endOfWord || alternative->chercherMot(mot) : mot[0] == lettre && endOfWord;
	else
	{
		if (mot[0] == lettre && suite != nullptr)
			return suite->chercherMot(mot.substr(1, mot.length() - 1));

		else if (mot[0] != lettre && alternative != nullptr) //TODO : si on conserve l'ordre lexicographique, on devrait pouvoir remplacer mot[0] != lettre par mot[0] > lettre,
			return alternative->chercherMot(mot);			 //       ce qui permettrait de sortir de la recherche beaucoup plus tôt

		else
			return false;
	}

}

bool Dictionnaire::estVide() const
{
	return lettre == 0;
}
