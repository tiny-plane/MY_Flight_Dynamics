#include "wing.h"

double wing::debug(int kind_debug)
{
	switch (kind_debug)
	{
	case 1:
		this->build();
			//return cac_wing_aera();
			return 0;
		break;
	default:
		break;
	}
	return 0;
}
bool wing::build(void)
{
	s[0] = new section();
	s[1] = new section();


	return true;
}
double wing::cac_wing_aera(void)
{
	for (int i = 0; i < this->slices; i++)
	{

	
		return 0;
}