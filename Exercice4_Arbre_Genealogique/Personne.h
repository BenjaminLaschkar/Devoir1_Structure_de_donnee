#pragma once

enum Couleur { Bleu, Marron };

class Personne
{
public:
	Personne(const char * nom, const char * prenom, int annee_de_naissance, enum Couleur couleur);
	~Personne();
private:
	const char * nom;
	const char * prenom;
	int annee_de_naissance;
	Couleur couleur;
};

