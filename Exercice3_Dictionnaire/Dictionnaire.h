#pragma once

#include <string>

/*
	Dictionnaire permettant de stocker des mots dans une structure semblable � un arbre de suffixes
*/

class Dictionnaire
{
public:

	//TODO : Cr�er un constructeur qui prend une liste d'intialisation en param�tre afin de pouvoir �crire :
	//       Dictionnaire dico = {"motUn","motDeux","motTrois","motQuatre"...};

	//Ajoute le mot au dictionnaire.
	Dictionnaire& ajouterMot(std::string const& mot);

	//Supprime le mot donn� du dictionnaire
	Dictionnaire& enleverMot(std::string const& mot);

	//Affiche le contenu du dictionnaire dans l'ordre lexicographique
	Dictionnaire& afficher() const;

	//Recherche la pr�sence du mot passer en param�tre dans le dictionnaire
	//Renvoie vrai si le mot existe, faux sinon
	bool chercherMot(std::string const& mot) const;

	bool estVide() const;

private:
	char lettre = 0;
	bool endOfWord = false;
	std::unique_ptr<Dictionnaire> suite = nullptr;
	std::unique_ptr<Dictionnaire> alternative = nullptr;
};