#include "mainheader.h"


class Maingame
{
private:
	// les plateaux de jeu
	Grille * joueur_;
	Grille * Ia_;

	// les bateaux du joueur
	Bateau *bateauJoueur_1;
	Bateau *bateauJoueur_2;
	Bateau *bateauJoueur_3;
	Bateau *bateauJoueur_4;
	Bateau *bateauJoueur_5;
	Bateau *bateauJoueur_6;
	int gagnerJoueur_; // indique combien de bateaux le jouer a détruit

	// les bateaux de l'Ia
	Bateau *bateauIa_1;
	Bateau *bateauIa_2;
	Bateau *bateauIa_3;
	Bateau *bateauIa_4;
	Bateau *bateauIa_5;
	Bateau *bateauIa_6;
	int gagnerIa_;		// indique combien de bateaux l'Ia a détruit

public:
	Maingame();				// constructeur
	~Maingame();			// Destructeur
	int isWin();			// 0 pour le joueur et 1 pour l'Ia ((indique si un joueur a gagné)
	void save();			// enregistrer
	void load();			// charger une partie
	void start();			// commnencer 
	void continueLast();	// Recommencer

};