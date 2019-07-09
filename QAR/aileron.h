#pragma once
#include "Control_surface.h"
namespace Flight
{
	class aileron : public Control_surface
	{
	private:
		double CYdr;
		double Cldr;
		double Cndr;
	public:
		aileron() :Control_surface(1), CYdr(0), Cldr(0), Cndr(0) {};
		Eigen::Vector4d Cac_vector();
	};
}