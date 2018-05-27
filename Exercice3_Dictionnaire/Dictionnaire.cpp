#include "Dictionnaire.h"

#include <iostream>

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

		else if (lettre > mot[0])
		{
			auto nouveauNoeud= std::unique_ptr<Dictionnaire>(new Dictionnaire()); //TODO : Une chose intéressante serait d'écrire un move constructor pour simplifier le code
			nouveauNoeud->lettre = lettre;
			nouveauNoeud->suite = std::move(suite);
			nouveauNoeud->alternative = std::move(alternative);
			
			lettre = mot[0];
			alternative = std::move(nouveauNoeud);
			endOfWord = true;
		}

		else if (alternative == nullptr)
		{
			alternative = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			alternative->ajouterMot(mot);
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
		{
			if (suite == nullptr)
				suite = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			suite->ajouterMot(mot.substr(1, mot.length() - 1));
		}

		else if (lettre > mot[0])
		{
			auto nouveauNoeud = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			nouveauNoeud->lettre = lettre;
			nouveauNoeud->suite = std::move(suite);
			nouveauNoeud->alternative = std::move(alternative);

			lettre = mot[0];
			alternative = std::move(nouveauNoeud);
			suite = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			suite->ajouterMot(mot.substr(1, mot.length() - 1));
		}

		else if (alternative == nullptr)
		{
			alternative = std::unique_ptr<Dictionnaire>(new Dictionnaire());
			alternative->ajouterMot(mot);
		}

		else
			alternative->ajouterMot(mot);
	}

	return *this; //Quand toutes les opérations sont finies, on peut renvoyer l'arbre modifié
}

void Dictionnaire::afficher() const
{
	std::string tampon = "";
	afficher(tampon);
}

void Dictionnaire::afficher(std::string& tampon) const
{
	if(!estVide())
	{
		tampon += lettre;

		if (endOfWord)
			std::cout << tampon << std::endl;

		if (suite != nullptr)
			suite->afficher(tampon);

		tampon.pop_back();

		if (alternative != nullptr)
			alternative->afficher(tampon);
	}
}

bool Dictionnaire::chercherMot(std::string const & mot) const
{
	if (estVide() || mot.empty())
		return false;

	else if(mot.length() == 1)
		return (alternative != nullptr) ? mot[0] == lettre && endOfWord || alternative->chercherMot(mot) : mot[0] == lettre && endOfWord;

	else
	{
		if (mot[0] == lettre && suite != nullptr)
			return suite->chercherMot(mot.substr(1, mot.length() - 1));

		else if (mot[0] != lettre && alternative != nullptr) //TODO : si on conserve l'ordre lexicographique, on devrait pouvoir remplacer mot[0] != lettre
			return alternative->chercherMot(mot);			 //       par mot[0] > lettre, ce qui permettrait de sortir de la recherche beaucoup plus tôt

		else
			return false;
	}
}

bool Dictionnaire::estVide() const
{
	return lettre == 0 && suite == nullptr && alternative == nullptr;
}
