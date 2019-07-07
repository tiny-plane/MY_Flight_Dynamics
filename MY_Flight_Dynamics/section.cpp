#include "section.h"

void section::Set_afil_type(int type)
{
	this->afil.type = type;
}

void section::Set_afil_afilname(std::string name)
{
	this->afil.afilname = name;
}
