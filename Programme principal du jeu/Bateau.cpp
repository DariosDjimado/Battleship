#include "Bateau.h"


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
	for (int i = 0; i < taille_; i++)cout << bateau_[i] << " ";
}