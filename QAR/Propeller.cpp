#include "Propeller.h"

Flight::Propeller::Propeller(int num):Thrust(Propellerthrust)
{
	this->number = num;
	this->d = new double[num];
	this->pos = new double[num];
	this->rps = new double[num];
}