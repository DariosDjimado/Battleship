#include<vector>
#include<list>
#include<iostream>

using namespace std;

class Grille
{
	vector <vector<int>>grille_;
	vector <vector<int>>bateaux_;
	int tailleGrille_;
	int nbrBateaux_;
	int tailleBateau_;
	
public:
	Grille(int tailleGrile = 10, int nbrBateaux = 6, int tailleBateau = 4);
	~Grille();
	void afficherGrille();
	void afficherAide();
	void placerBateaux();
};