#include "Grille.h"
#include<iostream>

using namespace std;

void main()
{
	Bateau bateauTest;
	bateauTest.afficher();
	Grille grille;
	cout << endl;
	grille.afficher();
	cout << endl;
	grille.placerBateaux(bateauTest,true);
	grille.afficher();
	cout << endl;
	int *val = new int;
	*val = 8;
	grille.setCaseValue(1, 0, val);
	bateauTest.afficher();
	cout << endl;
	cout << *val << endl;
	grille.afficher();
	cout << endl;
	cout << grille.getCaseValue(0, 0) << grille.getCaseValue(1, 0) << grille.getCaseValue(0, 1) << endl;
	system("pause");	
}