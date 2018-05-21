#include "stdafx.h"
#include "Arbre.h"



Arbre::Arbre(Noeud<Personne> racine)
{
	this->racine = racine;
}

Arbre::~Arbre()
{
}

void Arbre::ArbreAscendant()
{
	Noeud<Personne> actual_node = racine;

	while (actual_node.getParentGauche() != nullptr && actual_node.getParentDroit() != nullptr) {
		if (actual_node.data->GetPere() != nullptr) {
			Noeud<Personne> pere = Noeud<Personne>(actual_node.data->GetPere());
			actual_node.SetParentDroit(&pere);
		}
		if (actual_node.data->GetMere() != nullptr) {
			Noeud<Personne> mere = Noeud<Personne>(actual_node.data->GetMere());
			actual_node.SetParentDroit(&mere);
		}
	}
		//actual_node =
}

void Arbre::ArbreDescendant()
{
}
