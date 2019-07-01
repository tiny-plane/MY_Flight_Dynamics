#pragma once
#include <string>
class control_surface
{
	std::string name;
	double gain;
	/*
	control deflection gain, units:  degrees deflection / control variable
	*/
	double xhinge;
	/*
	x/c location of hinge.
	*/
	int XYZhvec;
	/*
	If positive, control surface extent is Xhinge..1  (TE surface)
	If negative, control surface extent is 0.. - Xhinge(LE surface)
	XYZhvec  vector giving hinge axis about which surface rotates*/
};
