#include <iostream>
#include"Grille.h"

using namespace std;



class Bateau
	
{
	int coordX_, coordY_;
	Grille * grille_;
	vector<int *> bateau_;
	int taille_;
	bool orientation_;
public:
	Bateau(Grille * grille, int coordX = 0, int coordY = 0, int taille = 4, bool orientation = true);
	~Bateau();
	int getCaseValue(int n) { return *bateau_[n]; }
	int getTaille() { return taille_; }
	bool getOrientation() { return orientation_; }
	void afficher();
	int getCoordX() { return coordX_; }
	int getCoordY() { return coordY_; }
	int etat(); // -1 : coulé ; 0 : non touché ; >0 : nombre de cases touchées
};