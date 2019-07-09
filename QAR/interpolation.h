#pragma once
#include <cstring>
namespace Flight
{
	class interpolation
	{
	private:
		int num = 10 ;
		double* x ;
		double* y ;
	public:
		interpolation(int num, double x[], double y[]);
		~interpolation() { delete this->x; delete this->y; }
	};
}