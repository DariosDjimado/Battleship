#include "Bateau.h"


using namespace std;

class Grille
{
	int coordX_;
	int coordY_;
	int nbColonnes_;
	int nbLignes_;
	vector<int> tabInit_;

	vector<vector <int*>> *tableau_ = new vector<vector<int*>>;

public:
	Grille(int coordX = 0, int coordY = 0, int nbLignes = 10, int nbColonnes = 10);
	~Grille();
	void setCaseValue(int x, int y, int *valeur);
	int getCaseValue(int x, int y);
	void placerBateaux(Bateau bateau, bool orientation);
	void afficher();

};