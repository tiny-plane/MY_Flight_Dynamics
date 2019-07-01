#pragma once
#include "control_surface.h"
class section
{
public:
	int num;/// 编号
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

	double afil[3];
	int Nchord = 10; ///number of chordwise horseshoe vortices placed on the surface
	
	int Nspan = 10; ///number of spanwise horseshoe vortices placed on the surface[optional]
	double Sspace = 1.0;/// spanwise vortex spacing parameter(described later)[optional]

	double scale[3];///scaling factors applied to all x, y, z coordinates

	double angle;
	/*The ANGLE keyword allows convenient changing of the incidence
	angle of the entire surface without the need to change the Ainc values
	for all the defining sections.  The rotation is performed about
	the spanwise axis projected onto the y-z plane. */

	bool nowake = false;
	/*The NOWAKE keyword specifies that this surface is to NOT shed a wake,
	so that its strips will not have their Kutta conditions imposed. 
	Such a surface will have a near-zero net lift, but it will still  
	generate a nonzero moment. */

	bool noalbe = false;
	/*The NOALBE keyword specifies that this surface is unaffected by freestream
	direction changes specified by the alpha,beta angles and p,q,r rotation rates. 
	This surface then reacts to only to the perturbation velocities of all the horseshoe 
	vortices and  sources and doublets in the flow. 
	This allows the SURFACE/NOALBE object to model fixed surfaces such as a ground plane,
	wind tunnel walls, or a nearby other aircraft  which is at a fixed flight condition. */

	bool noload = false;
	/*The NOLOAD keyword specifies that the force and moment on this surface is to NOT 
	be included in the overall forces and moments of the configuration. This is typically 
	used together with NOALBE, since the force on a ground plane or wind tunnel walls 
	certainly is not to be considered as part of the aircraft force of interest. */

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

	control_surface* cs; ///如果有control，再实例化这个控制面，否则不需要。
};