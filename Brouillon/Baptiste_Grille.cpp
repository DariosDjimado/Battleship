#include "Grille.h"
#include<iostream>
#include<string>
#include<Windows.h>

using namespace std;

Grille::Grille(int tailleGrile, int nbrBateaux, int tailleBateau)
{
	tailleGrille_ = tailleGrile;
	tailleBateau_ = tailleBateau;
	nbrBateaux_ = nbrBateaux;
	vector<int>ligne;
	vector<int>bateau;

	// initialisation de la grille
	for (int i = 0; i < tailleGrille_; i++)ligne.push_back(0); // Créée un vecteur ligne de 0
	for (int j = 0; j < tailleGrille_; j++)grille_.push_back(ligne);

	// initialisation des bateaux
	for (int i = 0; i < tailleBateau; i++)bateau.push_back(1);
	for (int j = 0; j < nbrBateaux_; j++)bateaux_.push_back(bateau);
}

Grille::~Grille()
{
	grille_.clear();
}

void Grille::afficherGrille()
{
	int case_ij = 0;
	vector<int>ligne;

	// Affiche le numéro des colonnes :
	cout << "    ";
	for (int i = 0; i < tailleGrille_; i++)
	{
		if (i < 9)cout << "c" << i + 1 << "  ";
		else cout << "c" << i + 1 << " ";
	}
	cout << endl;

	// Affiche les colonnes
	for (int i = 0; i < tailleGrille_; i++)
	{
		// Affiche le numéro de la ligne
		if (i < 9)cout << " l" << i+1 << "  ";
		else cout << "l" << i+1 << "  ";

		// Affiche la ligne
		for (int j = 0; j < tailleGrille_; j++)
		{
			ligne = grille_[i];
			case_ij = ligne[j];
			cout << case_ij;
			if (j < tailleGrille_ - 1)cout << " | ";
		}
		cout << endl;
	}
}

void Grille::afficherAide()
{
	cout << endl << " 0 : case vide" << endl << " 1 : bateau" << endl << " -1 : bateau touch\202" << endl << " -2 : case vide touch\202e" << endl;
}

void Grille::placerBateaux()
{
	string orientation;
	int numeroLigne;
	int numeroColonne;
	int emplacementValide=0;
	int nbrZeros = 0;
	int valeurCase;
	vector<int>ligne;
	vector<int>bateau;

	for (int i = 0; i < nbrBateaux_; i++)
	{
		while (emplacementValide == 0)
		{
			nbrZeros = 0;
			afficherGrille();
			afficherAide();

			// Demande à l'utilisateur l'orientation de son bateau
			orientation = "";
			cout << endl << "Comment voulez vous orienter votre bateau n\260" << i + 1 << " ? (horizontal : h, vetical : v)" << endl;
			while (orientation != "h" && orientation != "v")
			{
				cin >> orientation;
				if (orientation != "h" && orientation != "v")cout << "Erreur, veuillez entrer une donn\202e valide" << endl;
			}

			// Demande à l'utilisateur de placer son bateau sur la grille
			cout << endl << "O\227 voulez vous placer votre bateau ?" << endl << "Num\202ro de la colonne : ";
			cin >> numeroColonne;
			cout << "Num\202ro de la ligne : ";
			cin >> numeroLigne;
			cout << endl;

			// vérifie si le bateau ne sort pas de la grille
			if (tailleBateau_ + numeroColonne >= tailleGrille_ || tailleBateau_ + numeroLigne >= tailleGrille_)
			{
				cout << "Emplacement invalide : le bateau sort du plateau" << endl << endl;
				Sleep(1500);
			}
			else emplacementValide = 1;

			// vérifie si le bateau ne chevauche pas un autre bateau
			if (orientation == "h" && emplacementValide == 1)
			{
				ligne = grille_[numeroLigne - 1];
				for (int i = 0; i < tailleBateau_; i++)
					if (ligne[i + numeroColonne - 1] == 0)nbrZeros++;
			}
			if (orientation=="v" && emplacementValide == 1)
			{
				for (int i = 0; i < tailleBateau_; i++)
				{
					ligne = grille_[numeroLigne + i - 1];
					if (ligne[numeroColonne - 1] == 0)nbrZeros++;
				}
			}
			if (nbrZeros != tailleBateau_ && emplacementValide == 1)
			{
				emplacementValide = 0;
				cout << "Erreur : le bateau chevauche un autre bateau" << endl << endl;
				Sleep(1500);
			}

			// Placement du bateau sur la grille
			if (nbrZeros == tailleBateau_ && emplacementValide == 1)
			{
				if (orientation == "h")
				{
					ligne = grille_[numeroLigne - 1];
					for (int i = 0; i < tailleBateau_; i++)ligne[i + numeroColonne - 1] = 1;
					grille_[numeroLigne - 1] = ligne;
				}
				else
				{
					for (int i = 0; i < tailleBateau_; i++)
					{
						ligne = grille_[numeroLigne + i - 1];
						ligne[numeroColonne - 1] = 1;
						grille_[numeroLigne + i - 1] = ligne;
					}
				}
			}
		}
		


		
		emplacementValide = 0;
		
	}
}