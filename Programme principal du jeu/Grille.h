// Auteurs : DJIMADO , WOLFF

#include<vector>


using namespace std;

class Grille
{
	int nbColonnes_;
	int nbLignes_;


	vector<int> tabInit_; // Contient toutes les valeures de chaque case de la grille
	vector<vector <int*>> *tableau_ = new vector<vector<int*>>; // Contient des pointeurs vers les cases de tabInit

public:
	Grille(int nbLignes = 10, int nbColonnes = 10);
	~Grille();
	void setCaseValue(int x, int y, int valeur);
	int getCaseValue(int x, int y);
	int* getCaseAddr(int x, int y);
	bool verifierEmpl(int x,int y,bool orientation); // Vérifie le fait que l'on puisse placer un bateau sur l'emplacement désiré de la grille

	void afficher();
	int tirer(int x,int y); // Tirer sur une case de la grille
	int getTaille() const{ return nbColonnes_*nbLignes_; }

	void operator=(const Grille &g);
	int getTabInit(int i) const { return tabInit_[i]; }
	void setTabInit(int i, int valeur) { tabInit_[i] = valeur; }
};