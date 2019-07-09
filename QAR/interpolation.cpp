#include "interpolation.h"

Flight::interpolation::interpolation(int num,double x[], double y[])
{
	this->num = num;
	memcpy(this->x, x, num);
	memcpy(this->y, y, num);
}
