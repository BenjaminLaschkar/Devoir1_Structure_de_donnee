#pragma once

enum Couleur { Bleu, Marron };
using namespace std;

class Personne
{
public:
	Personne(const char * nom, const char * prenom, int annee_de_naissance, enum Couleur couleur);
	~Personne();
	const char * nom;
	const char * prenom;
	int annee_de_naissance;
	Couleur couleur;
};

