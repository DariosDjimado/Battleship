#include <iostream>
#include <vector>
using namespace std;

class Grille
{
	int coordX_;
	int coordY_;
	int nbColonnes_;
	int nbLignes_;
	int valInit_;

	vector<vector <int>> *tableau_ =new vector<vector<int>>;

public:
	Grille(int coordX=0,int coordY=0,int nbLignes=10, int nbColonnes=10,int valInit=0);
	~Grille();
	void setCaseValue(int x, int y,int valeur);
	int getCaseValue(int x, int y);

	void afficher();
};

class Bateau:public Grille
{
public:
	Bateau();
	~Bateau();
	void setOrientation(bool orientation); // verticale :true; horizontale: false
	vector<int> * touche();					// pointe sur un vecteur nul si le bateau n'a pas été touché, sinon renvoi les indices des cases touchées
	bool coule();					// si coulé true sinon false
	
};
