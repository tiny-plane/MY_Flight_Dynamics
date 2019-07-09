#include "Para.h"
#include <iostream>
void Flight::Para::Readfromavlrun()
{
}

bool Flight::Para::Readfromkeyboard()
{
	double temp;
	double inertia[3][3];
	std::cerr << "mass" << std::endl;
	std::cin >> temp;
	Set_mass(temp);
	std::cerr << "Sref" << std::endl;
	std::cin >> temp;
	Set_Sref(temp);
	std::cerr << "Cref" << std::endl;
	std::cin >> temp;
	Set_Cref(temp);
	std::cerr << "Bref" << std::endl;
	std::cin >> temp;
	Set_Bref(temp);
	std::cerr << "×ª¶¯¹ßÁ¿¾ØÕó" << std::endl;
	std::cin >> temp;
	Set_mass(temp);
	std::cerr << "mass" << std::endl;
	for (int i = 0;i <3;i++)
		for (int j=0;j<3;j++)
			std::cin >> inertia[i][j];
	Set_Inertia(inertia);
	return true;
}
