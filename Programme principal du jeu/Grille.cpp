#include <iostream>
#include "Grille.h"

Grille::Grille(int coordX, int coordY, int nbLignes, int nbColonnes)
{
	coordX_ = coordX;
	coordY_ = coordY;
	nbColonnes_ = nbColonnes;
	nbLignes_ = nbLignes;
	//for (int i = 0; i < nbColonnes_*nbLignes_; i++)tabInit_[i] = 0;
	tabInit_.resize(nbColonnes_*nbLignes_, 0);

	tableau_->resize(nbColonnes_);
	for (int i = 0; i < nbColonnes_; i++)
	{
		//((*tableau_)[i]).resize(nbLignes_);
		for (int j = 10 * i; j < 10 * i + nbLignes_; j++)
			((*tableau_)[i]).push_back(&tabInit_[j]);

	}
}

Grille::~Grille()
{
	tableau_->clear();
	free(tableau_);
}

void Grille::afficher()
{
	vector<vector<int*>>::iterator it;
	for (it = tableau_->begin(); it != tableau_->end(); it++)
	{
		vector<int*>::iterator it_int;
		for (it_int = it->begin(); it_int != it->end(); it_int++)
		{
			cout << *it_int << " " << (*(*it_int)) << " ";
		}
		cout << endl;
	}

}

void Grille::setCaseValue(int x, int y, int valeur)
{
	if (y < (int)tableau_->size() && x < (int)((*tableau_)[x]).size())
	{
		*(((*tableau_)[x])[y]) = valeur;
	}
}

int Grille::getCaseValue(int x, int y)
{
	if (y < (int)(*tableau_).size() && x < (int)((*tableau_)[x]).size())
	{
		return *((*tableau_)[x])[y];
	}
}

int* Grille::getCaseAddr(int x, int y)
{
	if (y < (int)(*tableau_).size() && x < (int)((*tableau_)[x]).size())
	{
		return ((*tableau_)[x])[y];
	}
}

/*void Grille::placerBateaux(Bateau bateau)
{
	if (bateau.getOrientation() == true) // Horizontal : true
	{
		for (int i = 0; i < (bateau).getTaille(); i++)
		{
			this->setCaseValue(bateau.getCoordX(), bateau.getCoordY() + i, 1);
			bateau.setCaseDest(this->getCaseAddr(bateau.getCoordX(), bateau.getCoordY() + i), i);
		}
	}
	else
	{
		for (int i = 0; i < (bateau).getTaille(); i++)
		{
			this->setCaseValue(bateau.getCoordX() + i, bateau.getCoordY(), 1);
			bateau.setCaseDest(this->getCaseAddr(bateau.getCoordX() + i, bateau.getCoordY()), i);
		}
	}
}*/