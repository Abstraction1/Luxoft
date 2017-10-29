#include "Cash.h"
#include <cstdlib>

racing::Cash::Cash()
{
	coordX_ = SetRandCoord();
	coordY_ = SetRandCoord();
	cashSymb_ = '$';
}

int racing::Cash::GetX() const
{
	return coordX_;
}

int racing::Cash::GetY() const
{
	return coordY_;
}

char racing::Cash::GetCashSymb() const
{
	return cashSymb_;
}
/*!
 * \function SetRandCoord 
 *
 * \author default
 * \date 29 10 2017
 *	
 * \TODO kill magic
 * 
 */
const int racing::Cash::SetRandCoord()
{
	return rand() % 18;
}



