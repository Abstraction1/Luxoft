#include "Cash.h"
#include <cstdlib>

racing::Cash::Cash()
{
	coordX_ = SetRandCoord();
	coordY_ = SetRandCoord();
	
	symb_ = new char('$');
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

racing::Cash::~Cash()
{
	delete symb_;
}



