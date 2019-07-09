#pragma once
#include "Control_surface.h"
namespace Flight
{
	class elevator : public Control_surface
	{
	private:
		double CLde;
		double Cmde;
		double CDde;
	public:
		elevator() :Control_surface(0),CLde(0),Cmde(0),CDde(0) {};
		Eigen::Vector4d Cac_vector();
	};
}