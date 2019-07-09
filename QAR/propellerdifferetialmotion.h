#pragma once
#include "Control_surface.h"
namespace Flight
{
	class propellerdifferentialmotion : public Control_surface
	{
	private:
		double ldm;
		double ndm;
		double Ydm;
	public:
		propellerdifferentialmotion() :Control_surface(1), ldm(0),ndm(0),Ydm(0) {};
		Eigen::Vector4d Cac_vector();
	};
}