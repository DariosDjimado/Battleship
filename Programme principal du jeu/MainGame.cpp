#include"MainGame.h"


Maingame::Maingame()
{

}

int Maingame::isWin()
{
	if (gagnerIa_ == 6)
		return 1;
	else
		if (gagnerJoueur_ == 6)
			return 0;
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