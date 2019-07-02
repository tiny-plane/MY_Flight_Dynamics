#include "var.h"

bool var::Init_var(void)
{
	return false;
}

void var::fresh_var(void)
{
	this->mach = this->velocity / this->local_speedofsound;
}

double var::get_alpha(void)
{
	return this->alpha;
}

double var::get_beta(void)
{
	return this->beta;
}

double var::get_mach(void)
{
	return this->mach;
}

double var::get_velocity(void)
{
	return this->velocity;
}

double var::get_Xref(void)
{
	return this->Xref;
}

double var::get_Yref(void)
{
	return this->Yref;
}

double var::get_Zref(void)
{
	return this->Zref;
}

double var::get_Sref(void)
{
	return this->Sref;
}

double var::get_Cref(void)
{
	return this->Cref;
}

double var::get_Bref(void)
{
	return this->Bref;
}

double var::get_mass(void)
{
	return this->mach;
}

double var::get_density(void)
{
	return this->density;
}

double var::get_gravity(void)
{
	return this->gravity;
}

double var::get_CDo(void)
{
	return this->CDo;
}

double var::get_Ixx(void)
{
	return this->I[0][0];
}

double var::get_Iyy(void)
{
	return this->I[1][1];
}

double var::get_Izz(void)
{
	return this->I[2][2];
}

double var::get_Ixy(void)
{
	return this->I[0][1];
}

double var::get_Iyz(void)
{
	return this->I[1][2];
}

double var::get_Izx(void)
{
	return this->I[0][2];
}

std::string var::get_name(void)
{
	return this->name;
}
