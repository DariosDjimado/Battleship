//#include "Bateau.h"
#include<vector>


using namespace std;

class Grille
{
	int coordX_;
	int coordY_;
	int nbColonnes_;
	int nbLignes_;
	int nbTableaux_;

	vector<int> tabInit_;
	vector<vector <int*>> *tableau_ = new vector<vector<int*>>;

public:
	Grille(int coordX = 0, int coordY = 0, int nbLignes = 10, int nbColonnes = 10);
	~Grille();
	void setCaseValue(int x, int y, int valeur);
	int getCaseValue(int x, int y);
	int* getCaseAddr(int x, int y);
	bool verifierEmpl(int x,int y,bool orientation);
	void setNbTableaux(int nb) { nbTableaux_ = nb; }
	void afficher();
	bool tirer(int x,int y);
};