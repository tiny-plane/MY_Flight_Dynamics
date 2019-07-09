#pragma once
#include "Control_surface.h"
namespace Flight
{
	class propellerthrust : public Control_surface
	{
	private:
		double Ldm;
		double mdm;
		double Ddm;
	public:
		propellerthrust() :Control_surface(0), Ldm(0), mdm(0), Ddm(0) {};
		Eigen::Vector4d Cac_vector();
	};
}