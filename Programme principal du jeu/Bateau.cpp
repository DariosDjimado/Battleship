#include "Bateau.h"


Bateau::Bateau(Grille * grille,int coordX, int coordY, int taille, bool orientation)
{
	taille_ = taille;
	orientation_ = orientation;
	grille_ = grille;
	coordX_ = coordX;
	coordY_ = coordY;

	// Place le bateau sur la grille :
	if (orientation_ == true) // Horizontal : true
	{
		for (int i = 0; i < taille_; i++)
		{
			if (grille_->getCaseValue(coordX_,coordY_+i)==0) grille_->setCaseValue(coordX_, coordY_ + i, 1);
			bateau_.push_back(grille_->getCaseAddr(coordX_, coordY_ + i));
		}
	}
	else
	{
		for (int i = 0; i < taille_; i++)
		{
			if (grille_->getCaseValue(coordX_+i, coordY_) == 0)grille_->setCaseValue(coordX_ + i, coordY_, 1);
			bateau_.push_back(grille_->getCaseAddr(coordX_ + i, coordY_));
		}
	}

}

Bateau::~Bateau()
{
	bateau_.clear();
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


void Bateau::afficher()
{
	//vector<int>::iterator it;
	//for (it = bateau_.begin(); it != bateau_.end(); it++)cout << *it << " ";
	for (int i = 0; i < taille_; i++)cout << bateau_[i] << " " << *bateau_[i] << " ";
}

/*void  Bateau::setCaseDest(int* caseBateau,int numeroCase)
{
	//bateau_.push_back(caseBateau);
	bateau_[numeroCase] = caseBateau;
}*/

int Bateau::etat()
{
	int casesTouchees = 0;
	for (int i = 0; i < taille_; i++)
	{
		if (getCaseValue(i) == -1)casesTouchees++;
	}
	if (casesTouchees == taille_)return -1;
	return casesTouchees;
}