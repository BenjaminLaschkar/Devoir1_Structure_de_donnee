#include <iostream>
#include "Dictionnaire.h"

int main()
{
	auto dico = std::unique_ptr<Dictionnaire>(new Dictionnaire());
	
	dico->ajouterMot("Arbre")
		.ajouterMot("Lit")
		.ajouterMot("Lasse")
		.afficher();

	dico->ajouterMot("Abas")
		.ajouterMot("Las")
		.ajouterMot("Arbuste")
		.ajouterMot("Bas")
		.afficher();

	std::cout << std::boolalpha
		<< dico->chercherMot("Arbre") << std::endl
		<< dico->chercherMot("Arbuste") << std::endl
		<< dico->chercherMot("Coucou") << std::endl;

	dico->enleverMot("Lasse").afficher();

	system("pause");
	return EXIT_SUCCESS;
}

