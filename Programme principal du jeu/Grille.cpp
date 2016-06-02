#include <iostream>
#include "Grille.h"

Grille::Grille(int coordX, int coordY, int nbLignes, int nbColonnes)
{
	coordX_ = coordX;
	coordY_ = coordY;
	nbColonnes_ = nbColonnes;
	nbLignes_ = nbLignes;
	tabInit_.resize(nbColonnes_*nbLignes_, 0);

	tableau_->resize(nbColonnes_);
	for (int i = 0; i < nbColonnes_; i++)
	{
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
	if (y < nbLignes_ && x < nbLignes_)
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

bool Grille::verifierEmpl(int x, int y, bool orientation)
{
	if (nbTableaux_ != 6)
	{
		bool possible = true;
		if (orientation == true) //horizontal
			if (y + 3 < 10)
			{
				for (int i = 0; i < 4; i++) if (getCaseValue(x, y + i) != 0) { possible = false; break; }
				return possible;
			}
			else
				return false;
		else //vertical
			if (x + 3 < 10)
			{
				for (int i = 0; i < 4; i++)
				{
					if (getCaseValue(x + i, y) != 0) {
						possible = false; break;
					}
				}
				return possible;
			}
			else
				return false;
	}
}

int Grille::tirer(int x, int y)
{
	int caseValue = getCaseValue(x, y);
	if (caseValue != 1 && caseValue != 0) return 0;
	else
	{
		if (caseValue == 0)
		{
			setCaseValue(x, y, -2);
				return -2;
		}
		else
		{
			setCaseValue(x, y, -1);
			return -1;
		}
		
	}
}
