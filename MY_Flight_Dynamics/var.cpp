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

void var::set_alpha(double alpha)
{
	this->alpha = alpha;
}

void var::set_beta(double beta)
{
	this->beta = beta;
}

void var::set_mach(double mach)
{
	this->mach = mach;
}

void var::set_velocity(double in)
{
	this->velocity = in;
}

void var::set_Xref(double in)
{
	this->Xref = in;
}

void var::set_Yref(double in)
{
	this->Yref = in;
}

void var::set_Zref(double in)
{
	this->Zref = in;
}

void var::set_Sref(double in)
{
	this->Sref = in;
}

void var::set_Cref(double in)
{
	this->Cref = in;
}

void var::set_Bref(double in)
{
	this->Bref = in;
}

void var::set_mass(double in)
{
	this->mass = in;
}

void var::set_density(double in)
{
	this->density = in;
}

void var::set_gravity(double in)
{
	this->gravity = in;
}

void var::set_CDo(double in)
{
	this->CDo = in;
}

void var::set_name(std:: string name)
{
	this->name = name;
}

void var::set_I(double Ixx, double Iyy, double Izz, double Ixy, double Iyz, double Izx)
{
	this->I[0][0] = Ixx;
	this->I[1][1] = Iyy;
	this->I[2][2] = Izz;
	this->I[0][1] = Ixy;
	this->I[1][2] = Iyz;
	this->I[0][2] = Izx;
}


std::string var::get_name(void)
{
	return this->name;
}
