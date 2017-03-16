// Auteurs : DJIMADO , WOLFF

#include "Bateau.h"
#include <fstream>
#include "CImg.h"
#include <stdlib.h>
#include <time.h>
using namespace cimg_library;
#include <string>

class Maingame
{
private:
	
	unsigned char * grid_color_ = new unsigned char;
	unsigned char * play1_color_ = new unsigned char;
	unsigned char * play2_color_ = new unsigned char;

	CImg<unsigned char> scene_;
	CImgDisplay disp_;

	// les plateaux de jeu
	Grille grilleJoueur_;
	Grille grilleIa_;
	vector<Bateau> bateauxJoueur_;
	vector<Bateau> bateauxIa_;



	int gagnerJoueur_; // indique combien de bateaux que le jouer a détruit
	int gagnerIa_;		// indique combien de bateaux que l'Ia a détruit

	
	bool tour_; // false = tour IA; true = tour Joueur

public:
	Maingame();				// constructeur
	~Maingame();			// Destructeur
	int isWin();			// 0 pour le joueur et 1 pour l'Ia ((indique si un joueur a gagné)
	void save(ofstream &ofs);			// enregistrer
	void load(ifstream &ifs);			// charger une partie

	void setBateauJoueur(int coordX=0, int coordY=0, int taille=4, bool orientation=true);
	void setBateauIa(int coordX = 0, int coordY = 0, int taille = 4, bool orientation = true);
	Bateau * getBateauJoueur(int n) { return &bateauxJoueur_[n]; }
	Bateau * getBateauIa(int n) { return &bateauxIa_[n]; }
	Grille * getGrilleJoueur() { return &grilleJoueur_; }
	Grille * getGrilleIa() { return &grilleIa_; }
	void start(); // Lancer une partie
	void clearDisp(); // Réinitialiser l'affichage

	void drawShip(int i, int j);
};