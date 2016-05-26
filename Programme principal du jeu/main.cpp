#include "Bateau.h"
#include<iostream>
#include <fstream>


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
	cout << endl;
	cout<<grille.placerBateaux(5,5, true);

	cout << endl;
	Bateau bat(&grille, 5, 5,4,true);
	grille.afficher();
	cout << endl;
	bat.afficher();
	cout << endl;

	ofstream flux("fichier.text");
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			flux << grille.getCaseValue(i, j) << " ";
		}
		flux << endl;
	}
	flux << endl;
	flux << bat.getCoordX() << " " << bat.getCoordY() << " " << endl;
	flux.close();
	system("pause");	
}