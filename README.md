# Battleship
Mini Projet 2016 Bataille navale

## Classes :
- ### Grille
Cette classe représente la grille de chaque joueur.
  - *Les champs*
    - *int* **nbColonnes_** : Nombre de colonnes de la grille

    - *int* **nbLignes_** : Nombre de lignes de la grille

    - *vector<int>* **tabInit_** : Tableau contenant les valeurs de toutes les cases de la grille

    - *vector<vector<int*\*>>\* **tableau_*** : Tableau contenant tous pointeurs de chaque élément du tableau *tabInit_*

  - *Les méthodes*
    - Publiques

      - **Grille**(int nbLignes = 10, int nbColonnes = 10) : Constructeur

      - ~**Grille**(): Destructeur

      - *void* **setCaseValue**(int x, int y, int valeur): Change la valeur d'une case à partir de ses coordonnées

      - *int* **getCaseValue**(int x, int y) : Retourne la valeur d'une case à partir de ses coordonnées

      - *int*\* **getCaseAddr**(int x, int y) : Retourne l'adresse d'une case à partir de ses coordonnées

      - *bool* **verifierEmpl**(int x,int y,bool orientation): Vérifie s'il est possible de placer un bateau.

      - *void* **afficher**();
      - *int* **tire**r(int x,int y); // Tirer sur une case de la grille

      - *int* **getTaille**() const
      - *void* **operator=**(const Grille &g);

      - *int* **getTabInit**(int i) const
      - *void* **setTabInit**(int i, int valeur)
- ### Bateau
  - Les champs

    - Privés

      - *int* **coordX_**, **coordY_**: Coordonnées x,y de la place du beatau sur la grille

      - *Grille* \* **grille_** : Pointeur sur la grille parente du bateau
      - *vector<int* \*> **bateau_**:

      - *int* **taille_**:  Taille du bateau
      - *bool* **orientation_**: Orientation du bateau

  - Les méthodes:
    - Publiques

      - **Bateau**(Grille * grille, int coordX = 0, int coordY = 0, int taille = 4, bool orientation = true): Constructeur

      - ~**Bateau**(): Destructeur
      - *int* **getCaseValue**(int n) Retourne la valeur de la case d'indice n

      - *int* **getTaille**() const : Retourne la taille du bateau
      - *bool* **getOrientation**() const : Retourne l'orientation du tableau

      - *void* **afficher**(): Affichage console
      - *int* **getCoordX**() const : Retourne la coordonnée X

      - *int* **getCoordY**() const : Retourne la cooredonnées Y
      - *int* **etat**() : Indique l'état du bateau
