#include <iostream>
#include "mainheader.h"

int main()
{
	Grille plateauDeJeu;
	plateauDeJeu.afficher();
	plateauDeJeu.setCaseValue(0, 2, 1);
	/*plateauDeJeu.setCaseValue(2, 4, 1);
	plateauDeJeu.setCaseValue(2, 5, 1);
	plateauDeJeu.setCaseValue(2, 6, 1);*/
	cout << endl << endl << endl;
	plateauDeJeu.afficher();
	cout << endl;

	Grille bateau(0, 0, 1, 4,1);
	bateau.afficher();

	cout << endl;

	bateau.setCaseValue(0, 2, 0);
	bateau.afficher();


	system("pause");
	return 0;
}