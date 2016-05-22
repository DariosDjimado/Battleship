#include "maingame.h"

Maingame::Maingame()
{

}

int Maingame::isWin()
{
	if (gagnerIa_ == 6)
		return 1;
	else
		if(gagnerJoueur_==6)
			return 0;
}