#include"D:\Users\Baptiste\Documents\Telecom Saint-Etienne\FI 1\Semestre 6\Mini projet informatique\BatailleNavale\include\PlateauJoueur.h"
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

	system("pause");
	
}