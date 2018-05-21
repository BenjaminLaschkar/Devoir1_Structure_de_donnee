#pragma once
#include <deque>
enum Couleur { Bleu, Marron };
using namespace std;

class Personne
{
public:
	Personne(const char * nom, const char * prenom, int annee_de_naissance, enum Couleur couleur);
	~Personne();
	void AjouterFemme(Personne &femme);
	void AjouterEnfant(Personne &enfant);
	void AjouterPere(Personne &pere);
	void AjouterMere(Personne &mere);
	Personne * GetFemme();
	deque<Personne *> GetEnfants();
	Personne * GetPere();
	Personne * GetMere();
	const char * nom;
	const char * prenom;
	int annee_de_naissance;
	Couleur couleur;

private:
	Personne * femme = nullptr;
	deque<Personne *> liste_enfant = deque<Personne*>();
	Personne * pere = nullptr;
	Personne * mere = nullptr;
};

