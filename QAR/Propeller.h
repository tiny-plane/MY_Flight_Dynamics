#pragma once
#include "interpolation.h"
#include "Thrust.h"
namespace Flight
{
	class Propeller : public Thrust
	{
	private:
		int number;//��������Ŀ�����֧��10��������
		double* d;//���������̴�С����λm
		double* pos;//����������������Գ�ƽ��ĳ��ȣ���λm
		double* dt;//������Ϣ
		double* rps;//ת����Ϣ
	public:
		Propeller(int num);
	};
}