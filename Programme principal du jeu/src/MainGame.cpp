//#include "MainGame.h"
#include"D:\Users\Baptiste\Documents\Telecom Saint-Etienne\FI 1\Semestre 6\Mini projet informatique\BatailleNavale\include\MainGame.h"

Maingame::Maingame()
{

}

int Maingame::isWin()
{
	if (gagnerIa_ == 6)
		return 1;
	else
		if (gagnerJoueur_ == 6)
			return 0;
}