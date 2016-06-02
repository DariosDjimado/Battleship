//#include "Bateau.h"
#include<vector>


using namespace std;

class Grille
{
	int nbColonnes_;
	int nbLignes_;
	int nbTableaux_;

	vector<int> tabInit_;
	vector<vector <int*>> *tableau_ = new vector<vector<int*>>;

public:
	Grille(int nbLignes = 10, int nbColonnes = 10);
	~Grille();
	void setCaseValue(int x, int y, int valeur);
	int getCaseValue(int x, int y);
	int* getCaseAddr(int x, int y);
	bool verifierEmpl(int x,int y,bool orientation);
	void setNbTableaux(int nb) { nbTableaux_ = nb; }
	void afficher();
	int tirer(int x,int y);
	int getTaille() const{ return nbColonnes_*nbLignes_; }
	int getNbTableaux() const { return nbTableaux_; }
	void operator=(const Grille &g);
	int getTabInit(int i) const { return tabInit_[i]; }
	void setTabInit(int i, int valeur) { tabInit_[i] = valeur; }
};