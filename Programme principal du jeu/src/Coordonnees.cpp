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
	cout << "Destruction des coordonn�es" << endl;
}

void Coordonnees::afficher() const
{
	cout << "Coordonn�es (" << coordX_ << ", " << coordY_ << ")" << endl;
}
