#include"MainGame.h"


Maingame::Maingame()
{
	tour_ = true;
	unsigned char
		grid_color[3] = { 0,0,255 },
		play1_color[3] = { 204,0,0 },
		play2_color[3] = { 0,102,0 };

	grid_color_ = grid_color;
	play1_color_ = play1_color;
	play2_color_ = play2_color;

	CImg <unsigned char> grid(1050, 600, 1, 3, 255);
	grid.draw_text(19, 14, "JOUER", play1_color, 0, 1, 25);
	grid.draw_text(110, 14, "SAUVER", play1_color, 0, 1, 25);
	grid.draw_text(203, 14, "CHARGER", play1_color, 0, 1, 25);
	grid.draw_text(309, 14, "REJOUER", play1_color, 0, 1, 25);
	for (int i = 0; i < 2; i++) grid.draw_line(0, 50 * i, 400, 50 * i, grid_color);
	for (int i = 1; i < 5; i++) grid.draw_line(100 * i, 0, 100 * i, 50, grid_color);
	for (int i = 2; i < 13; i++) grid.draw_line(0, 50 * i, 500, 50 * i, grid_color);
	for (int i = 2; i < 13; i++) grid.draw_line(550, 50 * i, 1050, 50 * i, grid_color);
	for (int j = 1; j < 21; j++) grid.draw_line(50 * j, 100, 50 * j, 600, grid_color);

	CImgDisplay disp(grid, "Bataille Navale", 0, false, false);
	disp_ = disp;

	disp_.move((CImgDisplay::screen_width() - disp.width()) / 2,
			(CImgDisplay::screen_height() - disp.height()) / 2);

	scene_ = grid;

}

int Maingame::isWin()
{
	if (gagnerIa_ == 6)
		return 1;
	else
		if (gagnerJoueur_ == 6)
			return 0;
		else
			return (-1);
}

void Maingame::save(ofstream &ofs)
{
	int tailleGrille = grilleJoueur_.getTaille();
	vector<Bateau>::iterator it;

	// "grilleJoueur ";
	for (int i = 0; i < tailleGrille; i++)
	{
		ofs << grilleJoueur_.getCaseValue(i / 10, i % 10);
	}

	ofs << endl;
	// "grilleIa ";
	for (int i = 0; i < tailleGrille; i++)
	{
		ofs << grilleIa_.getCaseValue(i / 10, i % 10);
	}
	ofs << endl;
	// "bateauxJoueur ";
	for ( it = bateauxJoueur_.begin(); it != bateauxJoueur_.end(); it++)
	{
		ofs << it->getCoordX()  << it->getCoordY()  << it->getTaille()  << it->getOrientation() ;
	}
	ofs <<  endl;
	// "bateauxIa ";
	for (it = bateauxIa_.begin(); it != bateauxIa_.end(); it++)
	{
		ofs << it->getCoordX()  << it->getCoordY()  << it->getTaille()  << it->getOrientation();
	}
	ofs << endl;
	// "gagnerJoueur" 
	ofs << gagnerJoueur_ << endl;
	// "gagnerIa"
	ofs  << gagnerIa_<< endl;
	ofs.close();

}

void Maingame::load(ifstream &ifs)
{
	string ligne, chaine;
	int tailleLigne, j=0, valeur;

	// load grilleJoueur
	getline(ifs, ligne);
	tailleLigne = ligne.size();
	for (int i = 0; i < tailleLigne; i++)
	{
		if (ligne[i] == '-')
		{
			chaine = ligne[i + 1];
			valeur = -stoi(chaine);
			grilleJoueur_.setCaseValue(j / 10, j % 10, valeur);
			i++;
		}
		else
		{
			chaine = ligne[i];
			valeur = stoi(chaine);
			grilleJoueur_.setCaseValue(j / 10, j % 10, valeur);
		}
		j++;
	}

	// load grilleIa
	j = 0;
	getline(ifs, ligne);
	tailleLigne = ligne.size();
	for (int i = 0; i < tailleLigne; i++)
	{
		if (ligne[i] == '-')
		{
			chaine = ligne[i + 1];
			valeur = -stoi(chaine);
			grilleIa_.setCaseValue(j / 10, j % 10,valeur);
			i++;
		}
		else
		{
			chaine = ligne[i];
			valeur = stoi(chaine);
			grilleIa_.setCaseValue(j / 10, j % 10, valeur);
		}
		j++;
	}
	
	// Bateaux joueur
	bateauxJoueur_.erase(bateauxJoueur_.begin(), bateauxJoueur_.end());
	getline(ifs, ligne);
	j = 0;
	string coordX, coordY, taille, orientation;
	for (int i = 0; i < 6; i++)
	{
		coordX = ligne[j];
		coordY = ligne[j + 1];
		taille = ligne[j + 2];
		orientation = ligne[j + 3];
		setBateauJoueur(stoi(coordX), stoi(coordY), stoi(taille), stoi(orientation)); // stoi orientation renvoi 1 ou 0 ce qui correspond bien à un boléen.
		j += 4;
	}
	
	// Bateaux Ia
	bateauxIa_.erase(bateauxIa_.begin(), bateauxIa_.end());
	getline(ifs, ligne);
	j = 0;
	for (int i = 0; i < 6; i++)
	{
		coordX = ligne[j];
		coordY = ligne[j + 1];
		taille = ligne[j + 2];
		orientation = ligne[j + 3];
		setBateauIa(stoi(coordX), stoi(coordY), stoi(taille), stoi(orientation)); // stoi orientation renvoi 1 ou 0 ce qui correspond bien à un boléen.
		j += 4;
	}
	
	// Gagner joueur
	getline(ifs, ligne);
	gagnerJoueur_ = stoi(ligne);
	// Gagner Ia
	getline(ifs, ligne);
	gagnerIa_ = stoi(ligne);
}

void Maingame::setBateauJoueur(int coordX, int coordY, int taille, bool orientation)
{
	bateauxJoueur_.push_back(Bateau(&grilleJoueur_, coordX, coordY, taille, orientation));
}

void Maingame::setBateauIa(int coordX, int coordY, int taille, bool orientation)
{
	bateauxIa_.push_back(Bateau(&grilleIa_, coordX, coordY, taille, orientation));
}

void Maingame::opsin()
{
	while (!disp_.is_closed() && !disp_.is_keyESC() && !disp_.is_keyQ()) {

		scene_.display(disp_);

		if (disp_.button() & 1) {
			int i = 12 * disp_.mouse_y() / disp_.height();
			int j = 21 * disp_.mouse_x() / disp_.width();
			if ((i != 1) || (i == 0 && j<8))
			{
				if (i == 0)
				{

					//Rejouer


					if(j>5)
					{
						clearDisp();
						bateauxJoueur_.clear();
						bateauxIa_.clear();
						grilleJoueur_ = Grille();
						grilleIa_ = Grille();
						gagnerIa_ = 0;
						gagnerJoueur_ = 0;
						tour_ = true;
						cout << endl;
						grilleIa_.afficher();
						cout << endl;
						grilleJoueur_.afficher();
						cout << endl;
					}


					//Charger


					if (j == 4 || j == 5)
					{
						ifstream ifs("sauvegarde.txt");
						load(ifs);
						clearDisp();
						int tailleGrille = grilleIa_.getTaille();
						for (int k = 0; k < tailleGrille; k++)
						{
							// Dessine sur la grille joueur
							int caseValue = grilleJoueur_.getCaseValue(k / 10, k % 10);
							int j = k % 10;
							int i = k / 10 + 2;
							if (caseValue ==-2|| caseValue ==-1)
							{
								scene_.draw_line(j * 50, i * 50, j * 50 + 50, i * 50 + 50, play2_color_);
								scene_.draw_line(j * 50 + 50, i * 50, j * 50, i * 50 + 50, play2_color_);
								if (caseValue == -1)scene_.draw_circle(j * 50 + 25, i * 50 + 25, 25, play2_color_, 1, ~0U);
							}
							if (caseValue == 1)
							{
								scene_.draw_circle(j * 50 + 25, i * 50 + 25, 25, play2_color_, 1, ~0U);
							}

							// Dessine sur la grille Ia
							caseValue = grilleIa_.getCaseValue(k / 10, k % 10);
							j = k % 10 + 11;
							if (caseValue == -2 || caseValue == -1)
							{
								scene_.draw_line(j * 50, i * 50, j * 50 + 50, i * 50 + 50, play2_color_);
								scene_.draw_line(j * 50 + 50, i * 50, j * 50, i * 50 + 50, play2_color_);
								if (caseValue == -1)scene_.draw_circle(j * 50 + 25, i * 50 + 25, 25, play2_color_, 1, ~0U);
							}
						}

					}


					//Sauvegarder


					if (j == 2 || j == 3) 
					{
						ofstream ofs("sauvegarde.txt");
						save(ofs);
					}

					// *********************************************************************************************************************
					// ************************************************* Jouer *************************************************************
					// *********************************************************************************************************************

					if (j < 2)
					{
						scene_.draw_text(509, 14, "Placez vos bateaux", play1_color_, 0, 1, 25);
						scene_.draw_text(489, 50, "H : Horizontal   V : Vertical", play1_color_, 0, 1, 25);
						while (bateauxJoueur_.size() < 6) // Le joueur place ses bateaux
						{
							if (disp_.button() & 1) {
								int i = 12 * disp_.mouse_y() / disp_.height();
								int j = 21 * disp_.mouse_x() / disp_.width();
								if (i > 1 && j < 10) drawShip(i, j);
							}
							scene_.display(disp_);
						}
						unsigned char white[3] = { 255,255,255 };
						scene_.draw_text(509, 14, "Placez vos bateaux", white, 0, 1, 25);
						scene_.draw_text(489, 50, "H : Horizontal   V : Vertical", white, 0, 1, 25);
						srand(time(NULL));
						while (bateauxIa_.size() < 6) // L'Ia place ses bateaux
						{
							
							int x, y;
							bool ori;
							x = rand() % 10;
							y = rand() % 10;
							cout << endl << endl;
							cout << "x : " << x << " y: " << y;
							cout << endl << endl;
							if (rand() % 2 == 1)ori = true;
							else ori = false;
							cout << "orientation " << ori;
							cout << endl << endl;
							if (grilleIa_.verifierEmpl(x,y,ori))bateauxIa_.push_back(Bateau(&grilleIa_, x, y, 4, ori));
						}
						cout << "fini" << endl;
						cout << endl << endl;
						grilleIa_.afficher();
						cout << endl << endl;

					}
				}
				else
				{
					if (i > 1 && j > 10)
					{
						if (tour_ && bateauxJoueur_.size()==6 && isWin()==-1) // Le joueur joue
						{
							int tirer = grilleIa_.tirer(i - 2, j - 11);
							if (tirer==-1) // Bateau touché
							{
								
								scene_.draw_circle(j * 50 + 25, i * 50 + 25, 25, play2_color_, 1, ~0U);
								scene_.draw_line(j * 50, i * 50, j * 50 + 50, i * 50 + 50, play2_color_);
								scene_.draw_line(j * 50 + 50, i * 50, j * 50, i * 50 + 50, play2_color_);
								tour_ = false;
								// On regarde le nombre de bateaux de l'Ia coulés
								int nbrBateauxCoulés = 0;
								for (int k = 0; k < 6; k++)
								{
									if (bateauxIa_[k].etat() == -1)nbrBateauxCoulés++;
								}
								gagnerJoueur_ = nbrBateauxCoulés;
							}
							if (tirer == -2) // Tir dans la mer
							{
								scene_.draw_line(j * 50, i * 50, j * 50 + 50, i * 50 + 50, play2_color_);
								scene_.draw_line(j * 50 + 50, i * 50, j * 50, i * 50 + 50, play2_color_);
								tour_ = false;
							}
								
								
							cout << endl << endl;
							grilleIa_.afficher();
							cout << endl << endl;
							srand(time(NULL));
							if (!tour_ && isWin()==-1) // L'Ia joue
							{
								int x, y;
								x = 0;
								y = 0;
								int tirer = 0;
								do
								{
									x = rand() % 10+2;
									y = rand() % 10;
									tirer = grilleJoueur_.tirer(x - 2, y);
									cout << x-2 << " " << y << endl;
									if (tirer != 0)
									{
										scene_.draw_line(y * 50, x * 50, y * 50 + 50, x * 50 + 50, play2_color_);
										scene_.draw_line(y * 50 + 50, x * 50, y * 50, x * 50 + 50, play2_color_);
										tour_ = true;
										cout << "je suis venu ici" << endl;
										if (tirer == -1)
										{
											int nbrBateauxCoulés = 0;
											for (int k = 0; k < 6; k++)
											{
												if (bateauxJoueur_[k].etat() == -1)nbrBateauxCoulés++;
											}
											gagnerIa_ = nbrBateauxCoulés;
										}
									}
								} while (tirer == 0 && tour_==false);
							}
							if(isWin()==1)scene_.draw_text(489, 50, "L'Ia a gagné", play1_color_, 0, 1, 25);
							if(isWin()==0)scene_.draw_text(489, 50, "Vous avez gagné !", play1_color_, 0, 1, 25);
						}
					}
				}
			}
		}
		disp_.wait();
		if (disp_.is_resized()) disp_.resize();
	}

}


void Maingame::drawShip(int i,int j)
{
	while (!disp_.is_keyH() && !disp_.is_keyV() /*&& !(disp_.button() & 1)*/);
	//if (disp_.button() & 1)return;
	if (disp_.is_keyH())
	{
		if (grilleJoueur_.verifierEmpl(i - 2, j, true))
		{
			for (int li = 0; li < 4; li++)scene_.draw_circle((j + li) * 50 + 25, i * 50 + 25, 25, play1_color_, 1, ~0U);
			bateauxJoueur_.push_back(Bateau(&grilleJoueur_, i - 2, j, 4, true));
		}
	}
	else
	{
		if (grilleJoueur_.verifierEmpl(i - 2, j, false))
		{
			for (int li = 0; li < 4; li++)scene_.draw_circle(j * 50 + 25, (i + li) * 50 + 25, 25, play1_color_, 1, ~0U);
			bateauxJoueur_.push_back(Bateau(&grilleJoueur_, i - 2, j, 4, false));
		}
	}
	

	grilleJoueur_.afficher();
}

void Maingame::clearDisp()
{
	CImg <unsigned char> grid(1050, 600, 1, 3, 255);
	grid.draw_text(19, 14, "JOUER", play1_color_, 0, 1, 25);
	grid.draw_text(110, 14, "SAUVER", play1_color_, 0, 1, 25);
	grid.draw_text(203, 14, "CHARGER", play1_color_, 0, 1, 25);
	grid.draw_text(309, 14, "REJOUER", play1_color_, 0, 1, 25);
	for (int i = 0; i < 2; i++) grid.draw_line(0, 50 * i, 400, 50 * i, grid_color_);
	for (int i = 1; i < 5; i++) grid.draw_line(100 * i, 0, 100 * i, 50, grid_color_);
	for (int i = 2; i < 13; i++) grid.draw_line(0, 50 * i, 500, 50 * i, grid_color_);
	for (int i = 2; i < 13; i++) grid.draw_line(550, 50 * i, 1050, 50 * i, grid_color_);
	for (int j = 1; j < 21; j++) grid.draw_line(50 * j, 100, 50 * j, 600, grid_color_);

	CImgDisplay disp(grid, "Bataille Navale", 0, false, false);
	disp_ = disp;
	scene_ = grid;
	disp_.move((CImgDisplay::screen_width() - disp.width()) / 2,
		(CImgDisplay::screen_height() - disp.height()) / 2);
}