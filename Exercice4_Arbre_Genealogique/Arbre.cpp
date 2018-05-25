#include "stdafx.h"
#include "Arbre.h"



Arbre::Arbre(Personne personne_racine)
{
	this->noeud_racine = Noeud<Personne>(&personne_racine);
}

Arbre::~Arbre()
{
}

void Arbre::ArbreAscendant(Noeud<Personne> &actual_node)
{
	/*
	Tout d'abord on regarde si on peux créer les noeud, on check dans les données si l

	*/
	if (!(actual_node.marquer)) {
		cout << 0;
		if (actual_node.data->GetPere() != nullptr) {
			static Noeud<Personne>  pere = Noeud<Personne>(actual_node.data->GetPere());
			actual_node.SetParentDroit(&pere);
			actual_node.getParentDroit().SetEnfant(&actual_node);
			cout << 1;
		}
		if (actual_node.data->GetMere() != nullptr) {
			static Noeud<Personne>  mere = Noeud<Personne>(actual_node.data->GetMere());
			actual_node.SetParentGauche(&mere);
			actual_node.getParentGauche().SetEnfant(&actual_node);
			cout << 2;
		}
		actual_node.marquer = true;
	}

	cout << 3;

	if (&actual_node.getParentGauche() == nullptr && &actual_node.getParentDroit() == nullptr) {
		cout << 4;
		if (&actual_node.getEnfant() != nullptr) {
			cout << 5;
			Arbre::ArbreAscendant(actual_node.getEnfant());
			return;
		}
		else {
			return;
		}
	}
	else {
		if (&actual_node.getParentGauche() != nullptr) {
			if ((&actual_node.getParentGauche())->marquer){
				return;
			}
			else {
				Arbre::ArbreAscendant(actual_node.getParentGauche());
			}
		}
		if (&actual_node.getParentDroit() != nullptr) {
			if ((&actual_node.getParentDroit())->marquer) {
				return;
			}
			else {
				Arbre::ArbreAscendant(actual_node.getParentDroit());
			}
		}
		return;
	}
	
	cout << "end";
}

void Arbre::ArbreDescendant()
{
}
