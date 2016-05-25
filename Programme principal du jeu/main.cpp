#include "Bateau.h"
#include<iostream>

using namespace std;

void main()
{
	
	Grille grille;
	Bateau bateauTest(&grille);
	cout << endl;
	grille.afficher();
	cout << endl;
	bateauTest.afficher();
	cout << endl;
	grille.setCaseValue(0, 3, 3);
	grille.afficher();
	cout << endl;
	bateauTest.afficher();
	system("pause");	
}