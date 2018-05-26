#pragma once

#include <string>

/*
	Dictionnaire permettant de stocker des mots dans une structure semblable à un arbre de suffixes
*/

class Dictionnaire
{
public:

	//TODO : Créer un constructeur qui prend une liste d'intialisation en paramètre afin de pouvoir écrire :
	//       Dictionnaire dico = {"motUn","motDeux","motTrois","motQuatre"...};

	//Ajoute le mot au dictionnaire.
	Dictionnaire& ajouterMot(std::string const& mot);

	//Supprime le mot donné du dictionnaire
	Dictionnaire& enleverMot(std::string const& mot);

	//Affiche le contenu du dictionnaire dans l'ordre lexicographique
	Dictionnaire& afficher() const;

	//Recherche la présence du mot passer en paramètre dans le dictionnaire
	//Renvoie vrai si le mot existe, faux sinon
	bool chercherMot(std::string const& mot) const;

	bool estVide() const;

private:
	char lettre = 0;
	bool endOfWord = false;
	std::unique_ptr<Dictionnaire> suite = nullptr;
	std::unique_ptr<Dictionnaire> alternative = nullptr;
};