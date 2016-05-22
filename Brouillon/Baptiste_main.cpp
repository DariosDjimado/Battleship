#include"Grille.h"
#include<iostream>
#include<Windows.h>

using namespace std;

void main()
{
	Grille grille1;
	grille1.afficherGrille();
	grille1.placerBateaux();

	Sleep(1000000);
}