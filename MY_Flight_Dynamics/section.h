#pragma once
#include "control_surface.h"
class section
{
public:
	int num;/// 编号
	double chord;
	double pos[3]; /// 前缘坐标 xyz
	/*Coordinate system
		---------------- -
		The geometry is described in the following Cartesian system :
	X downstream
		Y out the right wing
		Z up
		The freestream must be at a reasonably small angle to the X axis
		(alpha and beta must be small), since the trailing vorticity
		is oriented parallel to the X axis.The length unit used in
		this file is referred to as "Lunit".This is arbitrary,
		but must be the same throughout this file*/

	double afil[2] = {0.0,1.0};
	

	
	int Nspan = 10; ///number of spanwise horseshoe vortices placed on the surface[optional]
	double Sspace = 1.0;/// spanwise vortex spacing parameter(described later)[optional]

	

	double angle;
	/*The ANGLE keyword allows convenient changing of the incidence
	angle of the entire surface without the need to change the Ainc values
	for all the defining sections.  The rotation is performed about
	the spanwise axis projected onto the y-z plane. */

	

	int afile;
	/*The AFILE keyword is essentially the same as AIRFOIL, except that the x/c,y/c pairs
	are generated from a standard (XFOIL-type) set of airfoil coordinates contained in the file "filename". 
	The first line of this file is assumed to contain a string with the name of the airfoil 
	(as written out with XFOIL's SAVE command).  
	If the path/filename has embedded blanks double quotes should be used to delimit the string. */

	bool control = false;
	/*The CONTROL keyword declares that a hinge deflection at this section is to be governed by one or
	more control variables.  An arbitrary number of control variables can be used,
	limited only by the array limit NDMAX. */

	control_surface* cs[20]; ///如果有control，再实例化这个控制面，否则不需要。
};