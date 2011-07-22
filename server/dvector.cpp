#include <math.h>
#include "dvector.h"


float dVector::calcLength()
{
	return sqrt( x*x + y*y );
}

dVector dVector::operator+ ( dVector param ) 
{
	dVector temp( 0,0 );
	temp.x = x + param.x;
	temp.y = y + param.y;
	return ( temp );
}

dVector dVector::operator- ( dVector param ) 
{
	dVector temp( 0,0 );
	temp.x = x - param.x;
	temp.y = y - param.y;
	return ( temp );
}

void dVector::operator () ( int a, int b )
{
	x = a;
	y = b;
	return;
}