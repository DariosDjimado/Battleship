class Coordonnees
{
	int coordX_;
	int coordY_;
public:
	Coordonnees(int coordX = 0, int coordY = 0);
	int getCoordX() { return coordX_; }
	int getCoordY() { return coordY_; }

	//méthodes inutiles
	~Coordonnees();
	void afficher() const;



};