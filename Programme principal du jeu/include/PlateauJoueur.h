#include <iostream>
#include <vector>
using namespace std;


class Bateau
{
	vector<int> bateau_;
	int taille_;
	int coordX_;
	int coordY_;
public:
	Bateau(int coordX = 0, int coordY = 0, int taille = 4);
	~Bateau();
	int getCoordX() { return coordX_; }
	int getCoordY() { return coordY_; }
	int* getCaseValue(int n) { return &bateau_[n]; }
	int getTaille() { return taille_; }
	//void setOrientation(bool orientation); // vertical :true; horizontal: false
	//vector<int> * touche();					// pointe sur un vecteur nul si le bateau n'a pas été touché, sinon renvoi les indices des cases touchées
	//bool coule();					// si coulé true sinon false
	void afficher();
};

class Grille
{
	int coordX_;
	int coordY_;
	int nbColonnes_;
	int nbLignes_;
	int tabInit_[100];

	vector<vector <int*>> *tableau_ = new vector<vector<int*>>;

public:
	Grille(int coordX = 0, int coordY = 0, int nbLignes = 10, int nbColonnes = 10);
	~Grille();
	void setCaseValue(int x, int y, int *valeur);
	int getCaseValue(int x, int y);
	void placerBateaux(Bateau bateau,bool orientation);
	void afficher();

};

