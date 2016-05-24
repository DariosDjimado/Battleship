#include <iostream>
#include "Coordonnees.h"

using namespace std;

Coordonnees::Coordonnees(int coordX, int coordY)
{
	coordX_ = coordX;
	coordY_ = coordY;
}

Coordonnees::~Coordonnees()
{
	cout << "Destruction des coordonnées" << endl;
}

void Coordonnees::afficher() const
{
	cout << "Coordonnées (" << coordX_ << ", " << coordY_ << ")" << endl;
}
