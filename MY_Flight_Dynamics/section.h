#pragma once
#include "control_surface.h"
#include <string>
typedef struct
{
	int type = 1;//如果type =1 ,afilname为从外部输入的dat文件名，如'HN.dat"，如果type=0，afilname为NACA翼型的编号，如"0012"
	std::string afilname = "NACA0012.dat";
}Afil;

typedef struct
{
	int num = 0;
	control_surface* cs[10]; ///如果有control，再实例化这个控制面，否则不需要。
}Control;
class section
{
public:
	int num;/// 编号
	double chord=1;
	double pos[3] = {0.0,0.0,0.0}; /// 前缘坐标 xyz
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
	Afil afil;
	int Nspan = 5; ///number of spanwise horseshoe vortices placed on the surface[optional]
	int Sspace = 1;/// spanwise vortex spacing parameter(described later)[optional]
	double ainc = 0;///扭转角
	Control control;

	/*The CONTROL keyword declares that a hinge deflection at this section is to be governed by one or
	more control variables.  An arbitrary number of control variables can be used,
	limited only by the array limit NDMAX. */


public:
	section* front;
	section* after;
	void Set_pos(double pos[3])
	{
		this->pos[0] = pos[0];
		this->pos[1] = pos[1];
		this->pos[2] = pos[2];
	}
	const double* Get_pos() const
	{
		return this->pos;
	}
	void Set_afil(Afil afil)
	{
		this->afil = afil;
	}
	const Afil& Get_afil() const
	{
		return this->afil;
	}
	int Get_Nspan() const
	{
		return this->Nspan;
	}
	int Get_Sspace() const
	{
		return this->Sspace;
	}
	double Get_chord() const
	{
		return this->chord;
	}
	double Get_ainc() const
	{
		return this->ainc;
	}
	void Set_Nspan(int Nspan)
	{
		this->Nspan = Nspan;
	}
	void Set_Sspace(int Sspace)
	{
		this->Sspace = Sspace;
	}
	void Set_chord(double chord)
	{
		this->chord = chord;
	}
	void Set_ainc(double ainc)
	{
		this->ainc = ainc;
	}
	void Set_afil_type(int kind);
	void Set_afil_afilname(std::string name);
	bool Add_control(control_surface* control)
	{
		if (this->control.num == 10)
			return false;
		else
		{
			this->control.num++;
			this->control.cs[this->control.num - 1] = control;
			return true;
		}
	}
	bool Cancel_control(int number)
	{
		if (this->control.num == 0)
			return false;
		else
		{
			int i;
			for (i = number; i < this->control.num; i++)
				this->control.cs[i] = this->control.cs[i + 1];
			this->control.num = this->control.num - 1;
			return true;
		}
	}
	const control_surface* Get_controlsurface(int num)
	{
		return (this->control.cs[num - 1]);
	}

};