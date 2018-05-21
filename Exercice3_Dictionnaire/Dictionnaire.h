#pragma once

#include <string>

/*
	Dictionnaire permettant de stocker des mots dans une structure semblable à un arbre de suffixes
*/

class Dictionnaire
{
public:
	//Ajoute le mot au dictionnaire. Le convertit en majuscule si ce n'est pas déjà fait.
	Dictionnaire& ajouterMot(std::string const& mot);

	//Supprime le mot donné du dictionnaire
	Dictionnaire& enleverMot(std::string const& mot);

	//Affiche le contenu du dictionnaire dans l'ordre lexicographique
	Dictionnaire& afficher() const;

	//Recherche la présence du mot passer en paramètre dans le dictionnaire
	//Renvoie vrai si le mot existe, faux sinon
	bool chercherMot(std::string const& mot) const;

private:
	char lettre;
	bool endOfWord;
	std::unique_ptr<Dictionnaire> suite;
	std::unique_ptr<Dictionnaire> alternative;
};