#pragma once
#include "interpolation.h"
#include "Thrust.h"
namespace Flight
{
	class Propeller : public Thrust
	{
	private:
		int number;//螺旋桨数目，最多支持10个螺旋桨
		double* d;//螺旋桨桨盘大小，单位m
		double* pos;//螺旋桨距离飞行器对称平面的长度，单位m
		double* dt;//油门信息
		double* rps;//转速信息
	public:
		Propeller(int num);
	};
}