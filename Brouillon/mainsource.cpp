#include "mainheader.h"

Grille::Grille(int coordX , int coordY, int nbLignes, int nbColonnes,int valInit)
{
	coordX_ = coordX;
	coordY_ = coordY;
	nbColonnes_ = nbColonnes;
	nbLignes_ = nbLignes;
	valInit_ = valInit;

	(*tableau_).resize(nbColonnes_);
	for (int i = 0; i < nbColonnes_; i++)
	{
		((*tableau_)[i]).resize(nbLignes_, valInit_);
	}
}

Grille::~Grille()
{
	(*tableau_).clear();
	free(tableau_);
}

void Grille::afficher()
{
	vector<vector<int>>::iterator it;
	for (it = (*tableau_).begin(); it != (*tableau_).end(); it++)
	{
		vector<int>::iterator it_int;
		for (it_int = (*it).begin(); it_int != (*it).end(); it_int++)
		{
			cout << *it_int << " ";
		}
		cout << endl;
	}

}

void Grille::setCaseValue(int x, int y,int valeur)
{
	if (y < (int)(*tableau_).size() && x < (int)((*tableau_)[x]).size())
	{
		((*tableau_)[y])[x] = valeur;
	}
}

int Grille::getCaseValue(int x, int y)
{
	if (y < (int)(*tableau_).size() && x < (int)((*tableau_)[x]).size())
	{
		return ((*tableau_)[y])[x];
	}
}

bool Bateau::coule()
{
	bool coule = true;
	for (int i = 0; i < 4; i++)
	{
		if ((*this).getCaseValue(0,i) != 1)
		{
			coule = false;
			break;
		}
	}
	return coule;
}
