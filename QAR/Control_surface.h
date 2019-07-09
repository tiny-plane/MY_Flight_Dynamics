#pragma once
#include <Eigen\Dense>
namespace Flight
{
	class Control_surface
	{
	protected:
		int type;//0为纵向控制面，1为横航向控制面
	public:
		Control_surface(int type) :type(type) {};
		virtual Eigen::Vector4d Cac_vector();
	};
}