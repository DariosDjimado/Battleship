#include "Bateau.h"


Bateau::Bateau(Grille * grille,int coordX, int coordY, int taille, bool orientation)
	:Coordonnees(coordX,coordY)
{
	taille_ = taille;
	orientation_ = orientation;
	grille_ = grille;

	// Place le bateau sur la grille :
	if (orientation_ == true) // Horizontal : true
	{
		for (int i = 0; i < taille_; i++)
		{
			grille_->setCaseValue(getCoordX(), getCoordY() + i, 1);
			bateau_.push_back(grille_->getCaseAddr(getCoordX(),getCoordY() + i));
		}
	}
	/*else
	{
		for (int i = 0; i < (bateau).getTaille(); i++)
		{
			this->setCaseValue(bateau.getCoordX() + i, bateau.getCoordY(), 1);
			bateau.setCaseDest(this->getCaseAddr(bateau.getCoordX() + i, bateau.getCoordY()), i);
		}
	}*/

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