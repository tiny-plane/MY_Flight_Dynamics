#pragma once
#include <Eigen\Dense>
namespace Flight
{
	class Control_surface
	{
	protected:
		int type;//0Ϊ��������棬1Ϊ�ẽ�������
	public:
		Control_surface(int type) :type(type) {};
		virtual Eigen::Vector4d Cac_vector();
	};
}