//#include "PlateauJoueur.h"
#include"D:\Users\Baptiste\Documents\Telecom Saint-Etienne\FI 1\Semestre 6\Mini projet informatique\BatailleNavale\include\PlateauJoueur.h"

Grille::Grille(int coordX, int coordY, int nbLignes, int nbColonnes)
{
	coordX_ = coordX;
	coordY_ = coordY;
	nbColonnes_ = nbColonnes;
	nbLignes_ = nbLignes;
	for (int i = 0; i < nbColonnes_*nbLignes_; i++)tabInit_[i] = 0;

	(*tableau_).resize(nbColonnes_);
	for (int i = 0; i < nbColonnes_; i++)
	{
		//((*tableau_)[i]).resize(nbLignes_);
		for (int j = 10 * i; j < 10 * i + nbLignes_; j++)
			((*tableau_)[i]).push_back(&tabInit_[j]);

	}
}

Grille::~Grille()
{
	(*tableau_).clear();
	free(tableau_);
}

void Grille::afficher()
{
	vector<vector<int*>>::iterator it;
	for (it = (*tableau_).begin(); it != (*tableau_).end(); it++)
	{
		vector<int*>::iterator it_int;
		for (it_int = (*it).begin(); it_int != (*it).end(); it_int++)
		{
			cout << *it_int << " " << (*(*it_int)) << " ";
		}
		cout << endl;
	}

}

void Grille::setCaseValue(int x, int y, int *valeur)
{
	if (y < (int)(*tableau_).size() && x < (int)((*tableau_)[x]).size())
	{
		*(((*tableau_)[y])[x] )= *valeur;
	}
}

int Grille::getCaseValue(int x, int y)
{
	if (y < (int)(*tableau_).size() && x < (int)((*tableau_)[x]).size())
	{
		return *((*tableau_)[y])[x];
	}
}

/*bool Bateau::coule()
{
	bool coule = true;
	for (int i = 0; i < 4; i++)
	{
		if ((*this).getCaseValue(0, i) != 1)
		{
			coule = false;
			break;
		}
	}
	return coule;
}*/

Bateau::Bateau(int coordX, int coordY, int taille)
{
	taille_ = taille;
	coordX_ = coordX;
	coordY_ = coordY;
	for (int i = 0; i < taille; i++)bateau_.push_back(1);
}

Bateau::~Bateau()
{
	bateau_.clear();
}

void Grille::placerBateaux(Bateau bateau,bool orientation)
{
	if (orientation == true) // vertical : true
	{
		for (int i = 0; i < (bateau).getTaille(); i++)(*this).setCaseValue((bateau).getCoordX(), (bateau).getCoordY() + i, (bateau).getCaseValue(i));
	}
	else
	{
		for (int i = 0; i < (bateau).getTaille(); i++)(*this).setCaseValue((bateau).getCoordX() + i, (bateau).getCoordY(), (bateau).getCaseValue(i));
	}
}

void Bateau::afficher()
{
	//vector<int>::iterator it;
	//for (it = bateau_.begin(); it != bateau_.end(); it++)cout << *it << " ";
	for (int i = 0; i < taille_; i++)cout << bateau_[i] << " ";
}